/////////////////////////////////////////////////////////////////////////////
//
// Project ProjectForge Community Edition
//         www.projectforge.org
//
// Copyright (C) 2001-2026 Micromata GmbH, Germany (www.micromata.com)
//
// ProjectForge is dual-licensed.
//
// This community edition is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation; version 3 of the License.
//
// This community edition is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
// Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, see http://www.gnu.org/licenses/.
//
/////////////////////////////////////////////////////////////////////////////

#include "projectforge-common/Version.hpp"
#include <spdlog/spdlog.h>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

namespace org::projectforge {

static std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

Version::Version(const std::string& version) {
    if (version.empty()) {
        updateAsString();
        return;
    }
    std::string str = version;
    // Convert to lowercase
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    // Check for snapshot
    size_t snapshotPos = str.find("-snapshot");
    if (snapshotPos != std::string::npos) {
        snapshot_ = true;
        str = str.substr(0, snapshotPos);
    }

    // Check for beta
    std::string betaString;
    std::string releaseCandidateString;
    size_t betaPos = str.find('b');
    if (betaPos != std::string::npos) {
        betaString = str.substr(betaPos + 1);
        str = str.substr(0, betaPos);
    } else {
        size_t rcPos = str.find("rc");
        if (rcPos != std::string::npos) {
            releaseCandidateString = str.substr(rcPos + 2);
            str = str.substr(0, rcPos);
        }
    }

    auto sa = splitString(str, '.');
    if (sa.size() > 0) {
        majorRelease_ = parseInt(version, sa[0]);
        if (sa.size() > 1) {
            minorRelease_ = parseInt(version, sa[1]);
            if (sa.size() > 2) {
                patchLevel_ = parseInt(version, sa[2]);
                if (sa.size() > 3) {
                    buildNumber_ = parseInt(version, sa[3]);
                }
            }
        }
    }

    if (!betaString.empty()) {
        if (betaString.length() > 0) {
            betaVersion_ = parseInt(version, betaString);
        } else {
            betaVersion_ = 0;
        }
    }
    if (!releaseCandidateString.empty()) {
        if (releaseCandidateString.length() > 0) {
            releaseCandidateVersion_ = parseInt(version, releaseCandidateString);
        } else {
            releaseCandidateVersion_ = 0;
        }
    }
    updateAsString();
}

Version::Version(int majorRelease, int minorRelease)
    : Version(majorRelease, minorRelease, 0, 0) {}

Version::Version(int majorRelease, int minorRelease, int patchLevel)
    : Version(majorRelease, minorRelease, patchLevel, 0) {}

Version::Version(int majorRelease, int minorRelease, int patchLevel, int buildNumber)
    : majorRelease_(majorRelease), minorRelease_(minorRelease),
      patchLevel_(patchLevel), buildNumber_(buildNumber) {
    updateAsString();
}

Version& Version::setBetaVersion(int betaVersion) {
    betaVersion_ = betaVersion;
    updateAsString();
    return *this;
}

Version& Version::setReleaseCandidateVersion(int releaseCandidateVersion) {
    releaseCandidateVersion_ = releaseCandidateVersion;
    updateAsString();
    return *this;
}

int Version::compareTo(const Version& o) const {
    int cmp = compare(majorRelease_, o.majorRelease_);
    if (cmp != 0) return cmp;
    cmp = compare(minorRelease_, o.minorRelease_);
    if (cmp != 0) return cmp;
    cmp = compare(patchLevel_, o.patchLevel_);
    if (cmp != 0) return cmp;
    cmp = compare(buildNumber_, o.buildNumber_);
    if (cmp != 0) return cmp;

    if (isReleaseCandidate()) {
        if (o.isReleaseCandidate()) {
            return compare(releaseCandidateVersion_, o.releaseCandidateVersion_);
        } else if (o.isBeta()) {
            return 1; // RC is higher than beta
        } else {
            return -1; // RC is lower than normal
        }
    }
    if (o.isReleaseCandidate()) {
        if (isBeta()) {
            return -1; // beta is lower than RC
        } else {
            return 1; // normal version is higher than RC
        }
    }
    if (isBeta()) {
        if (o.isBeta()) {
            return compare(betaVersion_, o.betaVersion_);
        } else {
            return -1; // beta is lower than normal
        }
    }
    if (o.isBeta()) {
        return 1; // normal is higher than beta
    }
    return 0;
}

void Version::updateAsString() {
    std::stringstream sb;
    sb << majorRelease_;
    sb << '.' << minorRelease_;
    if (patchLevel_ != 0 || buildNumber_ != 0) {
        sb << '.' << patchLevel_;
        if (buildNumber_ != 0) {
            sb << '.' << buildNumber_;
        }
    }
    if (betaVersion_ < MAX_VALUE) {
        sb << 'b' << betaVersion_;
    } else if (releaseCandidateVersion_ < MAX_VALUE) {
        sb << "rc" << releaseCandidateVersion_;
    }
    if (snapshot_) {
        sb << "-SNAPSHOT";
    }
    asString_ = sb.str();
}

int Version::parseInt(const std::string& version, const std::string& str) const {
    if (!version.empty() && version.find("gradle.version") != std::string::npos) {
        auto log = spdlog::get("projectforge");
        if (log) {
            log->info("Not running in productive environment: version string is '?gradle.version?', assuming 0.");
        }
        return 0;
    }
    try {
        return std::stoi(str);
    } catch (const std::exception&) {
        auto log = spdlog::get("projectforge");
        if (log) {
            log->error("Can't parse version string '{}'. '{}' isn't a number", version, str);
        }
    }
    return 0;
}

int Version::compare(int i1, int i2) {
    if (i1 < i2) return -1;
    if (i1 > i2) return 1;
    return 0;
}

} // namespace org::projectforge
