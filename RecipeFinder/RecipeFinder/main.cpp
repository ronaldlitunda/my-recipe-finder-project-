#include "RecipeFinder.h"
#include "Recipe.h"

int main() {
    RecipeFinder finder;

    finder.addRecipe({ "Veggie Pasta", {"pasta", "tomato", "onion", "pepper"}, 350, 4.5, {"vegetarian"}, {"Delicious!"} });
    finder.addRecipe({ "Chicken Salad", {"chicken", "lettuce", "tomato"}, 250, 4.2, {"gluten-free"}, {"Healthy and tasty"} });
    finder.addRecipe({ "Fruit Smoothie", {"banana", "strawberry", "yogurt"}, 180, 4.8, {"vegetarian", "gluten-free"}, {"Refreshing"} });

    std::vector<std::string> userIngredients = { "banana", "strawberry", "yogurt" };
    std::vector<std::string> dietaryPrefs = { "vegetarian" };

    finder.searchRecipes(userIngredients, dietaryPrefs);
    finder.visualizeRecipes();
    finder.generateShoppingList(userIngredients);
    finder.rateRecipe("Fruit Smoothie", 5.0, "Awesome drink!");

    return 0;
}
