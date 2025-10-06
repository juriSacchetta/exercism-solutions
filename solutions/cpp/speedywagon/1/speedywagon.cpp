#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
    bool connection_check(pillar_men_sensor* s) {
        return s != nullptr;
    }

int activity_counter(pillar_men_sensor s[], int n){
        int c = 0;
        for(int i = 0; i<n; i++) {
            c += s[i].activity;
        }
        return c;
    }

    bool alarm_control(pillar_men_sensor* s) {
        if(!connection_check(s)) return false;
        return s->activity > 0;
    }

    bool uv_alarm(pillar_men_sensor* s) {
        if(!connection_check(s)) return false;
        return uv_light_heuristic(&s->data) > (*s).activity;
    }

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
