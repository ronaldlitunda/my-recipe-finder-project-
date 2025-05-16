#ifndef RECIPE_FINDER_H
#define RECIPE_FINDER_H

#include "Recipe.h"
#include <vector>
#include <string>

class RecipeFinder {
public:
    void addRecipe(const Recipe& recipe);
    void rateRecipe(const std::string& recipeName, float rating, const std::string& review);
    void searchRecipes(const std::vector<std::string>& userIngredients, const std::vector<std::string>& dietaryPrefs);
    void generateShoppingList(const std::vector<std::string>& userIngredients);
    void visualizeRecipes();
};

#endif

