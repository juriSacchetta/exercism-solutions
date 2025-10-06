#include "power_of_troy.h"

namespace troy {

    void give_new_artifact(human& h, std::string name) {
        h.possession = std::make_unique<artifact>(name);
    }

    void exchange_artifacts(std::unique_ptr<artifact>& a1, std::unique_ptr<artifact>& a2){
        a1.swap(a2);
    }

    void manifest_power(human& h, std::string s) {
        h.own_power = std::make_shared<power>(s);
    }

    void use_power(human& h1, human& h2) {
        h2.influenced_by = h1.own_power;
    }

    int power_intensity(human& h) {
        return h.own_power.use_count();
    }

}  // namespace troy
