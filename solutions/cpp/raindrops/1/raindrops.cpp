#include "raindrops.h"

namespace raindrops {

// TODO: add your solution here
    std::string convert(int s){
        std::string result = "";
        if(s%3 ==0) {
            result += "Pling";
        }
        if(s % 5 == 0){
            result += "Plang";
        }
        if(s%7==0){
            result += "Plong";
        }
        if(result == ""){
            result = std::to_string(s);
        }
        return result;
    }

}  // namespace raindrops
