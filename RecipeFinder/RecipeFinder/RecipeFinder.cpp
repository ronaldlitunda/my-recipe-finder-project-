#include "RecipeFinder.h"
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Helper namespace for utility functions
namespace {
    unordered_set<string> normalizeIngredients(const vector<string>& ingredients) {
        unordered_set<string> normalized;
        for (string ing : ingredients) {
            transform(ing.begin(), ing.end(), ing.begin(), ::tolower);
            normalized.insert(ing);
        }
        return normalized;
    }

    bool matchesDiet(const Recipe& recipe, const vector<string>& prefs) {
        for (const auto& tag : prefs)
            if (find(recipe.dietaryTags.begin(), recipe.dietaryTags.end(), tag) == recipe.dietaryTags.end())
                return false;
        return true;
    }

    float computeSimilarity(const unordered_set<string>& userIngredients, const vector<string>& recipeIngredients) {
        int match = 0;
        for (const auto& ing : recipeIngredients)
            if (userIngredients.count(ing)) match++;
        return static_cast<float>(match) / recipeIngredients.size();
    }
}

// Moved recipes to be a static member-like global in this file
vector<Recipe> recipes;

void RecipeFinder::addRecipe(const Recipe& recipe) {
    recipes.push_back(recipe);
}

void RecipeFinder::rateRecipe(const string& recipeName, float rating, const string& review) {
    for (auto& r : recipes) {
        if (r.name == recipeName) {
            r.reviews.push_back(review);
            r.rating = (r.rating + rating) / 2.0f;
            break;
        }
    }
}

void RecipeFinder::searchRecipes(const vector<string>& userIngredientsVec, const vector<string>& dietaryPrefs) {
    auto userIngredients = normalizeIngredients(userIngredientsVec);
    cout << "Matching Recipes:\n";
    for (const auto& r : recipes) {
        if (matchesDiet(r, dietaryPrefs)) {
            float similarity = computeSimilarity(userIngredients, r.ingredients);
            if (similarity > 0.5) {
                cout << "- " << r.name << " (" << r.calories << " kcal, Rating: "
                    << r.rating << ", Similarity: " << similarity << ")\n";
            }
        }
    }
}

void RecipeFinder::generateShoppingList(const vector<string>& userIngredientsVec) {
    auto userIngredients = normalizeIngredients(userIngredientsVec);
    unordered_map<string, int> missing;
    for (const auto& r : recipes)
        for (const auto& ing : r.ingredients)
            if (!userIngredients.count(ing))
                missing[ing]++;

    cout << "\nSuggested Shopping List:\n";
    for (const auto& entry : missing)
        cout << "- " << entry.first << " (missing in " << entry.second << " recipes)\n";
}

void RecipeFinder::visualizeRecipes() {
    cout << "\nRecipe Summary:\n";
    for (const auto& r : recipes) {
        cout << "- " << r.name << ": " << r.calories << " kcal, Rating: "
            << r.rating << ", Tags: ";
        for (const auto& tag : r.dietaryTags)
            cout << tag << " ";
        cout << "\n";
    }
}
