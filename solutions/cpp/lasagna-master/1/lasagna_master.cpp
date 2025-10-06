#include "lasagna_master.h"

namespace lasagna_master {
    int preparationTime(std::vector<std::string> layers, int averageTimePerLayer) {
        return  layers.size() * averageTimePerLayer;
    }
    amount quantities(std::vector<std::string> a) {
        amount result = {0, 0.0};
        for (auto x : a) {
            if(x == "sauce") 
                    result.sauce += 0.2;
            else if(x == "noodles")
                    result.noodles += 50;
        }
        return result;
    }

    void addSecretIngredient(std::vector<std::string>& ingredients, const std::vector<std::string>& friends_ingredients) {
    const std::string& secret = friends_ingredients.back();
    ingredients.pop_back();
    ingredients.push_back(secret);
    }

    std::vector<double> scaleRecipe(const std::vector<double> quantities, const int num) {
        std::vector<double> res;
        for (auto q : quantities) {
            res.push_back(q*num/2);
        }
        return res;
    }
    void addSecretIngredient(std::vector<std::string>& myList, const std::string sec) {
        myList.pop_back();
        myList.push_back(sec);
    } 
}  // namespace lasagna_master
