#pragma once
#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};
    
int preparationTime(std::vector<std::string> layers, int averageTimePerLayer=2);
amount quantities(std::vector<std::string> a);
void addSecretIngredient(std::vector<std::string>& ingredients, const std::vector<std::string>& friends_ingredients);
std::vector<double> scaleRecipe(const std::vector<double> quantities, const int num);
void addSecretIngredient(std::vector<std::string>& myList, const std::string sec);
}  // namespace lasagna_master
