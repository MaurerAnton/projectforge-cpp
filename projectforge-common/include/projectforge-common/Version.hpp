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

#pragma once

#include <string>
#include <compare>

namespace org::projectforge {

/**
 * Represents a version number (major-release, minor-release, patch-level and build-number).
 */
class Version {
public:
    static constexpr int MAX_VALUE = 2147483647; // Integer.MAX_VALUE

    /** Supported formats: "#" ("3"), "#.#" ("3.5"), "#.#.#" ("3.5.4") or "#.#.#.#" ("3.5.4.2").
     *  Append b# for marking version as beta version. */
    explicit Version(const std::string& version = "");

    Version(int majorRelease, int minorRelease);
    Version(int majorRelease, int minorRelease, int patchLevel);
    Version(int majorRelease, int minorRelease, int patchLevel, int buildNumber);

    int getMajorRelease() const { return majorRelease_; }
    int getMinorRelease() const { return minorRelease_; }
    int getPatchLevel() const { return patchLevel_; }
    int getBuildNumber() const { return buildNumber_; }

    Version& setBetaVersion(int betaVersion);
    int getBetaVersion() const { return betaVersion_; }
    bool isBeta() const { return betaVersion_ < MAX_VALUE; }

    int getReleaseCandidateVersion() const { return releaseCandidateVersion_; }
    Version& setReleaseCandidateVersion(int releaseCandidateVersion);
    bool isReleaseCandidate() const { return releaseCandidateVersion_ < MAX_VALUE; }

    bool isSnapshot() const { return snapshot_; }

    int compareTo(const Version& o) const;
    auto operator<=>(const Version& o) const { return compareTo(o) <=> 0; }
    bool operator==(const Version& o) const { return compareTo(o) == 0; }

    std::string toString() const { return asString_; }

private:
    int majorRelease_ = 0;
    int minorRelease_ = 0;
    int patchLevel_ = 0;
    int buildNumber_ = 0;
    int betaVersion_ = MAX_VALUE;
    int releaseCandidateVersion_ = MAX_VALUE;
    bool snapshot_ = false;
    std::string asString_;

    void updateAsString();
    int parseInt(const std::string& version, const std::string& str) const;
    static int compare(int i1, int i2);
};

} // namespace org::projectforge
