#include "doctor_data.h"
#include <utility>

using star_map::System;

namespace heaven {
Vessel::Vessel(std::string n, int generation)
    : name(std::move(n)), generation(generation), current_system(System::Sol) {}

Vessel::Vessel(std::string n, int generation, System s)
    : name(std::move(n)), generation(generation), current_system(s) {}

Vessel Vessel::replicate(std::string new_name) {
    return Vessel(std::move(new_name), ++generation, current_system);
}

void Vessel::make_buster() { ++busters; }

bool Vessel::shoot_buster() { if (busters) { --busters; return true; } return false; }

std::string get_older_bob(const Vessel& v1, const Vessel& v2) {
    if(v2.generation > v1.generation) {return v1.name;}
    return "";
}
bool in_the_same_system(const Vessel& v1, Vessel& v2) {
    return v1.current_system == v2.current_system;
}
} // namespace heaven
