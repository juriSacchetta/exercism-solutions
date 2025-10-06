#pragma once
#include <string>

namespace star_map {
enum class System {
    BetaHydri,
    EpsilonEridani,
    AlphaCentauri,
    DeltaEridani,
    Omicron2Eridani,
    Sol
};
}

namespace heaven {
class Vessel {
public:
    std::string      name{};
    int              generation{0};
    star_map::System current_system{star_map::System::Sol};
    int              busters{0};
    
    Vessel(std::string name, int generation);
    Vessel(std::string name, int generation, star_map::System s);
    Vessel replicate(std::string str);
    void make_buster();
    bool shoot_buster();
};
    std::string get_older_bob(const Vessel& v1, const Vessel& v2);
    bool in_the_same_system(const Vessel& v1, Vessel& v2);
}