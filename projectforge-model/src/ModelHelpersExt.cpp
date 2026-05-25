// ProjectForge C++ port — GPL v3 — www.projectforge.org

#include "org/projectforge/model/rest/AbstractBaseObject.hpp"
#include <nlohmann/json.hpp>
#include <chrono>

namespace model1 {
struct ModelHelper1 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=1; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model2 {
struct ModelHelper2 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=2; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model3 {
struct ModelHelper3 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=3; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model4 {
struct ModelHelper4 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=4; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model5 {
struct ModelHelper5 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=5; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model6 {
struct ModelHelper6 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=6; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model7 {
struct ModelHelper7 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=7; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model8 {
struct ModelHelper8 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=8; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model9 {
struct ModelHelper9 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=9; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model10 {
struct ModelHelper10 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=10; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model11 {
struct ModelHelper11 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=11; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model12 {
struct ModelHelper12 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=12; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model13 {
struct ModelHelper13 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=13; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model14 {
struct ModelHelper14 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=14; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model15 {
struct ModelHelper15 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=15; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model16 {
struct ModelHelper16 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=16; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model17 {
struct ModelHelper17 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=17; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model18 {
struct ModelHelper18 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=18; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model19 {
struct ModelHelper19 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=19; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model20 {
struct ModelHelper20 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=20; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model21 {
struct ModelHelper21 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=21; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model22 {
struct ModelHelper22 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=22; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model23 {
struct ModelHelper23 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=23; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model24 {
struct ModelHelper24 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=24; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model25 {
struct ModelHelper25 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=25; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model26 {
struct ModelHelper26 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=26; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model27 {
struct ModelHelper27 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=27; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model28 {
struct ModelHelper28 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=28; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model29 {
struct ModelHelper29 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=29; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model30 {
struct ModelHelper30 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=30; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model31 {
struct ModelHelper31 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=31; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model32 {
struct ModelHelper32 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=32; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model33 {
struct ModelHelper33 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=33; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model34 {
struct ModelHelper34 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=34; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model35 {
struct ModelHelper35 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=35; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model36 {
struct ModelHelper36 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=36; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model37 {
struct ModelHelper37 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=37; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model38 {
struct ModelHelper38 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=38; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model39 {
struct ModelHelper39 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=39; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model40 {
struct ModelHelper40 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=40; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model41 {
struct ModelHelper41 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=41; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model42 {
struct ModelHelper42 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=42; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model43 {
struct ModelHelper43 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=43; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model44 {
struct ModelHelper44 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=44; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model45 {
struct ModelHelper45 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=45; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model46 {
struct ModelHelper46 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=46; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model47 {
struct ModelHelper47 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=47; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model48 {
struct ModelHelper48 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=48; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model49 {
struct ModelHelper49 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=49; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model50 {
struct ModelHelper50 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=50; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model51 {
struct ModelHelper51 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=51; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model52 {
struct ModelHelper52 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=52; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model53 {
struct ModelHelper53 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=53; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model54 {
struct ModelHelper54 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=54; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model55 {
struct ModelHelper55 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=55; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model56 {
struct ModelHelper56 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=56; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model57 {
struct ModelHelper57 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=57; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model58 {
struct ModelHelper58 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=58; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model59 {
struct ModelHelper59 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=59; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model60 {
struct ModelHelper60 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=60; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model61 {
struct ModelHelper61 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=61; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model62 {
struct ModelHelper62 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=62; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model63 {
struct ModelHelper63 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=63; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model64 {
struct ModelHelper64 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=64; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model65 {
struct ModelHelper65 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=65; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model66 {
struct ModelHelper66 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=66; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model67 {
struct ModelHelper67 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=67; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model68 {
struct ModelHelper68 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=68; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model69 {
struct ModelHelper69 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=69; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model70 {
struct ModelHelper70 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=70; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model71 {
struct ModelHelper71 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=71; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model72 {
struct ModelHelper72 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=72; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model73 {
struct ModelHelper73 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=73; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model74 {
struct ModelHelper74 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=74; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model75 {
struct ModelHelper75 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=75; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model76 {
struct ModelHelper76 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=76; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model77 {
struct ModelHelper77 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=77; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model78 {
struct ModelHelper78 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=78; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model79 {
struct ModelHelper79 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=79; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model80 {
struct ModelHelper80 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=80; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model81 {
struct ModelHelper81 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=81; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model82 {
struct ModelHelper82 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=82; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model83 {
struct ModelHelper83 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=83; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model84 {
struct ModelHelper84 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=84; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model85 {
struct ModelHelper85 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=85; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model86 {
struct ModelHelper86 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=86; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model87 {
struct ModelHelper87 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=87; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model88 {
struct ModelHelper88 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=88; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model89 {
struct ModelHelper89 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=89; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model90 {
struct ModelHelper90 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=90; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model91 {
struct ModelHelper91 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=91; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model92 {
struct ModelHelper92 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=92; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model93 {
struct ModelHelper93 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=93; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model94 {
struct ModelHelper94 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=94; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model95 {
struct ModelHelper95 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=95; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model96 {
struct ModelHelper96 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=96; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model97 {
struct ModelHelper97 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=97; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model98 {
struct ModelHelper98 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=98; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model99 {
struct ModelHelper99 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=99; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model100 {
struct ModelHelper100 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=100; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model101 {
struct ModelHelper101 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=101; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model102 {
struct ModelHelper102 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=102; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model103 {
struct ModelHelper103 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=103; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model104 {
struct ModelHelper104 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=104; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model105 {
struct ModelHelper105 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=105; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model106 {
struct ModelHelper106 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=106; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model107 {
struct ModelHelper107 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=107; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model108 {
struct ModelHelper108 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=108; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model109 {
struct ModelHelper109 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=109; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model110 {
struct ModelHelper110 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=110; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model111 {
struct ModelHelper111 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=111; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model112 {
struct ModelHelper112 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=112; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model113 {
struct ModelHelper113 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=113; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model114 {
struct ModelHelper114 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=114; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model115 {
struct ModelHelper115 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=115; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model116 {
struct ModelHelper116 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=116; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model117 {
struct ModelHelper117 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=117; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model118 {
struct ModelHelper118 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=118; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model119 {
struct ModelHelper119 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=119; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model120 {
struct ModelHelper120 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=120; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model121 {
struct ModelHelper121 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=121; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model122 {
struct ModelHelper122 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=122; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model123 {
struct ModelHelper123 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=123; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model124 {
struct ModelHelper124 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=124; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model125 {
struct ModelHelper125 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=125; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model126 {
struct ModelHelper126 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=126; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model127 {
struct ModelHelper127 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=127; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model128 {
struct ModelHelper128 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=128; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model129 {
struct ModelHelper129 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=129; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model130 {
struct ModelHelper130 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=130; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model131 {
struct ModelHelper131 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=131; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model132 {
struct ModelHelper132 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=132; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model133 {
struct ModelHelper133 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=133; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model134 {
struct ModelHelper134 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=134; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model135 {
struct ModelHelper135 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=135; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model136 {
struct ModelHelper136 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=136; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model137 {
struct ModelHelper137 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=137; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model138 {
struct ModelHelper138 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=138; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model139 {
struct ModelHelper139 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=139; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model140 {
struct ModelHelper140 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=140; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model141 {
struct ModelHelper141 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=141; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model142 {
struct ModelHelper142 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=142; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model143 {
struct ModelHelper143 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=143; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model144 {
struct ModelHelper144 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=144; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model145 {
struct ModelHelper145 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=145; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model146 {
struct ModelHelper146 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=146; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model147 {
struct ModelHelper147 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=147; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model148 {
struct ModelHelper148 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=148; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model149 {
struct ModelHelper149 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=149; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model150 {
struct ModelHelper150 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=150; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model151 {
struct ModelHelper151 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=151; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model152 {
struct ModelHelper152 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=152; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model153 {
struct ModelHelper153 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=153; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model154 {
struct ModelHelper154 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=154; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model155 {
struct ModelHelper155 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=155; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model156 {
struct ModelHelper156 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=156; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model157 {
struct ModelHelper157 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=157; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model158 {
struct ModelHelper158 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=158; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model159 {
struct ModelHelper159 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=159; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model160 {
struct ModelHelper160 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=160; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model161 {
struct ModelHelper161 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=161; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model162 {
struct ModelHelper162 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=162; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model163 {
struct ModelHelper163 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=163; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model164 {
struct ModelHelper164 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=164; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model165 {
struct ModelHelper165 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=165; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model166 {
struct ModelHelper166 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=166; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model167 {
struct ModelHelper167 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=167; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model168 {
struct ModelHelper168 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=168; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model169 {
struct ModelHelper169 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=169; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model170 {
struct ModelHelper170 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=170; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model171 {
struct ModelHelper171 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=171; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model172 {
struct ModelHelper172 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=172; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model173 {
struct ModelHelper173 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=173; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model174 {
struct ModelHelper174 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=174; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model175 {
struct ModelHelper175 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=175; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model176 {
struct ModelHelper176 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=176; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model177 {
struct ModelHelper177 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=177; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model178 {
struct ModelHelper178 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=178; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model179 {
struct ModelHelper179 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=179; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model180 {
struct ModelHelper180 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=180; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model181 {
struct ModelHelper181 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=181; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model182 {
struct ModelHelper182 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=182; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model183 {
struct ModelHelper183 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=183; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model184 {
struct ModelHelper184 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=184; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model185 {
struct ModelHelper185 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=185; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model186 {
struct ModelHelper186 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=186; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model187 {
struct ModelHelper187 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=187; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model188 {
struct ModelHelper188 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=188; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model189 {
struct ModelHelper189 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=189; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model190 {
struct ModelHelper190 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=190; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model191 {
struct ModelHelper191 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=191; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model192 {
struct ModelHelper192 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=192; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model193 {
struct ModelHelper193 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=193; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model194 {
struct ModelHelper194 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=194; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model195 {
struct ModelHelper195 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=195; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model196 {
struct ModelHelper196 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=196; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model197 {
struct ModelHelper197 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=197; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model198 {
struct ModelHelper198 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=198; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model199 {
struct ModelHelper199 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=199; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model200 {
struct ModelHelper200 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=200; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model201 {
struct ModelHelper201 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=201; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model202 {
struct ModelHelper202 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=202; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model203 {
struct ModelHelper203 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=203; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model204 {
struct ModelHelper204 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=204; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model205 {
struct ModelHelper205 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=205; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model206 {
struct ModelHelper206 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=206; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model207 {
struct ModelHelper207 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=207; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model208 {
struct ModelHelper208 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=208; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model209 {
struct ModelHelper209 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=209; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model210 {
struct ModelHelper210 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=210; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model211 {
struct ModelHelper211 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=211; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model212 {
struct ModelHelper212 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=212; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model213 {
struct ModelHelper213 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=213; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model214 {
struct ModelHelper214 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=214; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model215 {
struct ModelHelper215 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=215; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model216 {
struct ModelHelper216 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=216; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model217 {
struct ModelHelper217 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=217; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model218 {
struct ModelHelper218 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=218; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model219 {
struct ModelHelper219 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=219; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model220 {
struct ModelHelper220 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=220; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model221 {
struct ModelHelper221 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=221; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model222 {
struct ModelHelper222 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=222; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model223 {
struct ModelHelper223 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=223; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model224 {
struct ModelHelper224 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=224; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model225 {
struct ModelHelper225 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=225; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model226 {
struct ModelHelper226 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=226; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model227 {
struct ModelHelper227 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=227; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model228 {
struct ModelHelper228 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=228; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model229 {
struct ModelHelper229 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=229; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model230 {
struct ModelHelper230 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=230; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model231 {
struct ModelHelper231 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=231; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model232 {
struct ModelHelper232 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=232; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model233 {
struct ModelHelper233 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=233; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model234 {
struct ModelHelper234 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=234; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model235 {
struct ModelHelper235 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=235; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model236 {
struct ModelHelper236 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=236; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model237 {
struct ModelHelper237 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=237; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model238 {
struct ModelHelper238 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=238; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model239 {
struct ModelHelper239 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=239; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model240 {
struct ModelHelper240 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=240; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model241 {
struct ModelHelper241 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=241; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model242 {
struct ModelHelper242 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=242; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model243 {
struct ModelHelper243 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=243; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model244 {
struct ModelHelper244 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=244; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model245 {
struct ModelHelper245 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=245; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model246 {
struct ModelHelper246 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=246; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model247 {
struct ModelHelper247 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=247; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model248 {
struct ModelHelper248 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=248; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model249 {
struct ModelHelper249 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=249; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model250 {
struct ModelHelper250 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=250; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model251 {
struct ModelHelper251 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=251; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model252 {
struct ModelHelper252 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=252; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model253 {
struct ModelHelper253 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=253; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model254 {
struct ModelHelper254 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=254; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model255 {
struct ModelHelper255 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=255; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model256 {
struct ModelHelper256 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=256; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model257 {
struct ModelHelper257 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=257; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model258 {
struct ModelHelper258 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=258; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model259 {
struct ModelHelper259 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=259; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model260 {
struct ModelHelper260 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=260; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model261 {
struct ModelHelper261 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=261; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model262 {
struct ModelHelper262 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=262; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model263 {
struct ModelHelper263 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=263; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model264 {
struct ModelHelper264 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=264; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model265 {
struct ModelHelper265 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=265; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model266 {
struct ModelHelper266 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=266; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model267 {
struct ModelHelper267 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=267; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model268 {
struct ModelHelper268 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=268; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model269 {
struct ModelHelper269 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=269; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model270 {
struct ModelHelper270 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=270; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model271 {
struct ModelHelper271 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=271; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model272 {
struct ModelHelper272 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=272; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model273 {
struct ModelHelper273 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=273; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model274 {
struct ModelHelper274 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=274; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model275 {
struct ModelHelper275 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=275; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model276 {
struct ModelHelper276 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=276; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model277 {
struct ModelHelper277 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=277; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model278 {
struct ModelHelper278 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=278; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model279 {
struct ModelHelper279 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=279; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model280 {
struct ModelHelper280 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=280; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model281 {
struct ModelHelper281 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=281; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model282 {
struct ModelHelper282 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=282; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model283 {
struct ModelHelper283 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=283; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model284 {
struct ModelHelper284 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=284; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model285 {
struct ModelHelper285 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=285; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model286 {
struct ModelHelper286 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=286; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model287 {
struct ModelHelper287 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=287; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model288 {
struct ModelHelper288 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=288; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model289 {
struct ModelHelper289 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=289; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model290 {
struct ModelHelper290 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=290; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model291 {
struct ModelHelper291 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=291; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model292 {
struct ModelHelper292 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=292; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model293 {
struct ModelHelper293 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=293; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model294 {
struct ModelHelper294 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=294; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model295 {
struct ModelHelper295 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=295; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model296 {
struct ModelHelper296 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=296; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model297 {
struct ModelHelper297 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=297; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model298 {
struct ModelHelper298 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=298; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model299 {
struct ModelHelper299 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=299; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model300 {
struct ModelHelper300 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=300; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model301 {
struct ModelHelper301 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=301; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model302 {
struct ModelHelper302 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=302; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model303 {
struct ModelHelper303 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=303; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model304 {
struct ModelHelper304 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=304; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model305 {
struct ModelHelper305 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=305; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model306 {
struct ModelHelper306 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=306; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model307 {
struct ModelHelper307 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=307; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model308 {
struct ModelHelper308 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=308; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model309 {
struct ModelHelper309 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=309; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model310 {
struct ModelHelper310 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=310; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model311 {
struct ModelHelper311 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=311; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model312 {
struct ModelHelper312 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=312; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model313 {
struct ModelHelper313 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=313; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model314 {
struct ModelHelper314 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=314; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model315 {
struct ModelHelper315 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=315; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model316 {
struct ModelHelper316 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=316; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model317 {
struct ModelHelper317 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=317; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model318 {
struct ModelHelper318 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=318; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model319 {
struct ModelHelper319 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=319; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model320 {
struct ModelHelper320 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=320; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model321 {
struct ModelHelper321 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=321; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model322 {
struct ModelHelper322 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=322; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model323 {
struct ModelHelper323 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=323; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model324 {
struct ModelHelper324 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=324; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model325 {
struct ModelHelper325 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=325; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model326 {
struct ModelHelper326 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=326; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model327 {
struct ModelHelper327 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=327; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model328 {
struct ModelHelper328 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=328; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model329 {
struct ModelHelper329 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=329; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model330 {
struct ModelHelper330 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=330; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model331 {
struct ModelHelper331 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=331; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model332 {
struct ModelHelper332 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=332; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model333 {
struct ModelHelper333 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=333; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model334 {
struct ModelHelper334 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=334; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model335 {
struct ModelHelper335 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=335; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model336 {
struct ModelHelper336 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=336; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model337 {
struct ModelHelper337 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=337; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model338 {
struct ModelHelper338 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=338; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model339 {
struct ModelHelper339 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=339; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model340 {
struct ModelHelper340 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=340; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model341 {
struct ModelHelper341 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=341; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model342 {
struct ModelHelper342 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=342; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model343 {
struct ModelHelper343 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=343; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model344 {
struct ModelHelper344 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=344; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model345 {
struct ModelHelper345 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=345; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model346 {
struct ModelHelper346 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=346; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model347 {
struct ModelHelper347 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=347; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model348 {
struct ModelHelper348 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=348; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model349 {
struct ModelHelper349 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=349; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model350 {
struct ModelHelper350 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=350; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model351 {
struct ModelHelper351 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=351; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model352 {
struct ModelHelper352 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=352; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model353 {
struct ModelHelper353 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=353; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model354 {
struct ModelHelper354 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=354; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model355 {
struct ModelHelper355 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=355; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model356 {
struct ModelHelper356 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=356; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model357 {
struct ModelHelper357 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=357; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model358 {
struct ModelHelper358 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=358; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model359 {
struct ModelHelper359 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=359; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model360 {
struct ModelHelper360 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=360; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model361 {
struct ModelHelper361 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=361; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model362 {
struct ModelHelper362 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=362; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model363 {
struct ModelHelper363 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=363; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model364 {
struct ModelHelper364 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=364; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model365 {
struct ModelHelper365 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=365; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model366 {
struct ModelHelper366 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=366; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model367 {
struct ModelHelper367 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=367; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model368 {
struct ModelHelper368 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=368; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model369 {
struct ModelHelper369 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=369; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model370 {
struct ModelHelper370 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=370; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model371 {
struct ModelHelper371 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=371; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model372 {
struct ModelHelper372 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=372; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model373 {
struct ModelHelper373 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=373; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model374 {
struct ModelHelper374 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=374; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model375 {
struct ModelHelper375 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=375; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model376 {
struct ModelHelper376 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=376; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model377 {
struct ModelHelper377 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=377; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model378 {
struct ModelHelper378 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=378; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model379 {
struct ModelHelper379 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=379; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model380 {
struct ModelHelper380 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=380; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model381 {
struct ModelHelper381 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=381; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model382 {
struct ModelHelper382 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=382; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model383 {
struct ModelHelper383 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=383; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model384 {
struct ModelHelper384 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=384; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model385 {
struct ModelHelper385 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=385; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model386 {
struct ModelHelper386 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=386; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model387 {
struct ModelHelper387 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=387; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model388 {
struct ModelHelper388 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=388; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model389 {
struct ModelHelper389 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=389; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model390 {
struct ModelHelper390 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=390; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model391 {
struct ModelHelper391 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=391; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model392 {
struct ModelHelper392 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=392; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model393 {
struct ModelHelper393 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=393; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model394 {
struct ModelHelper394 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=394; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model395 {
struct ModelHelper395 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=395; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model396 {
struct ModelHelper396 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=396; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model397 {
struct ModelHelper397 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=397; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model398 {
struct ModelHelper398 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=398; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model399 {
struct ModelHelper399 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=399; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model400 {
struct ModelHelper400 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=400; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model401 {
struct ModelHelper401 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=401; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model402 {
struct ModelHelper402 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=402; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model403 {
struct ModelHelper403 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=403; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model404 {
struct ModelHelper404 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=404; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model405 {
struct ModelHelper405 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=405; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model406 {
struct ModelHelper406 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=406; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model407 {
struct ModelHelper407 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=407; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model408 {
struct ModelHelper408 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=408; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model409 {
struct ModelHelper409 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=409; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model410 {
struct ModelHelper410 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=410; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model411 {
struct ModelHelper411 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=411; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model412 {
struct ModelHelper412 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=412; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model413 {
struct ModelHelper413 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=413; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model414 {
struct ModelHelper414 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=414; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model415 {
struct ModelHelper415 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=415; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model416 {
struct ModelHelper416 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=416; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model417 {
struct ModelHelper417 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=417; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model418 {
struct ModelHelper418 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=418; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model419 {
struct ModelHelper419 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=419; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model420 {
struct ModelHelper420 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=420; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model421 {
struct ModelHelper421 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=421; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model422 {
struct ModelHelper422 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=422; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model423 {
struct ModelHelper423 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=423; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model424 {
struct ModelHelper424 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=424; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model425 {
struct ModelHelper425 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=425; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model426 {
struct ModelHelper426 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=426; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model427 {
struct ModelHelper427 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=427; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model428 {
struct ModelHelper428 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=428; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model429 {
struct ModelHelper429 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=429; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model430 {
struct ModelHelper430 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=430; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model431 {
struct ModelHelper431 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=431; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model432 {
struct ModelHelper432 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=432; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model433 {
struct ModelHelper433 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=433; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model434 {
struct ModelHelper434 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=434; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model435 {
struct ModelHelper435 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=435; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model436 {
struct ModelHelper436 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=436; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model437 {
struct ModelHelper437 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=437; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model438 {
struct ModelHelper438 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=438; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model439 {
struct ModelHelper439 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=439; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model440 {
struct ModelHelper440 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=440; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model441 {
struct ModelHelper441 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=441; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model442 {
struct ModelHelper442 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=442; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model443 {
struct ModelHelper443 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=443; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model444 {
struct ModelHelper444 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=444; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model445 {
struct ModelHelper445 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=445; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model446 {
struct ModelHelper446 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=446; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model447 {
struct ModelHelper447 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=447; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model448 {
struct ModelHelper448 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=448; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model449 {
struct ModelHelper449 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=449; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model450 {
struct ModelHelper450 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=450; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model451 {
struct ModelHelper451 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=451; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model452 {
struct ModelHelper452 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=452; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model453 {
struct ModelHelper453 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=453; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model454 {
struct ModelHelper454 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=454; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model455 {
struct ModelHelper455 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=455; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model456 {
struct ModelHelper456 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=456; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model457 {
struct ModelHelper457 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=457; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model458 {
struct ModelHelper458 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=458; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model459 {
struct ModelHelper459 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=459; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model460 {
struct ModelHelper460 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=460; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model461 {
struct ModelHelper461 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=461; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model462 {
struct ModelHelper462 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=462; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model463 {
struct ModelHelper463 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=463; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model464 {
struct ModelHelper464 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=464; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model465 {
struct ModelHelper465 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=465; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model466 {
struct ModelHelper466 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=466; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model467 {
struct ModelHelper467 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=467; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model468 {
struct ModelHelper468 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=468; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model469 {
struct ModelHelper469 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=469; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model470 {
struct ModelHelper470 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=470; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model471 {
struct ModelHelper471 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=471; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model472 {
struct ModelHelper472 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=472; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model473 {
struct ModelHelper473 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=473; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model474 {
struct ModelHelper474 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=474; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model475 {
struct ModelHelper475 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=475; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model476 {
struct ModelHelper476 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=476; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model477 {
struct ModelHelper477 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=477; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model478 {
struct ModelHelper478 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=478; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model479 {
struct ModelHelper479 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=479; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model480 {
struct ModelHelper480 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=480; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model481 {
struct ModelHelper481 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=481; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model482 {
struct ModelHelper482 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=482; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model483 {
struct ModelHelper483 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=483; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model484 {
struct ModelHelper484 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=484; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model485 {
struct ModelHelper485 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=485; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model486 {
struct ModelHelper486 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=486; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model487 {
struct ModelHelper487 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=487; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model488 {
struct ModelHelper488 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=488; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model489 {
struct ModelHelper489 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=489; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model490 {
struct ModelHelper490 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=490; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model491 {
struct ModelHelper491 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=491; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model492 {
struct ModelHelper492 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=492; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model493 {
struct ModelHelper493 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=493; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model494 {
struct ModelHelper494 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=494; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model495 {
struct ModelHelper495 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=495; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model496 {
struct ModelHelper496 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=496; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model497 {
struct ModelHelper497 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=497; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model498 {
struct ModelHelper498 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=498; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model499 {
struct ModelHelper499 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=499; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}

namespace model500 {
struct ModelHelper500 {
    static nlohmann::json wrap(const nlohmann::json& d) { nlohmann::json r; r["data"]=d; r["ok"]=true; r["h"]=500; return r; }
    static nlohmann::json list(int p, int ps) { nlohmann::json r; r["page"]=p; r["pageSize"]=ps; r["items"]=nlohmann::json::array(); return r; }
    static bool valid(const nlohmann::json& d) { return d.contains("id"); }
};
}
