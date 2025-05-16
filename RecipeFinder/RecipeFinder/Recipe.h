#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

struct Recipe {
    std::string name;
    std::vector<std::string> ingredients;
    int calories;
    float rating;
    std::vector<std::string> dietaryTags;
    std::vector<std::string> reviews;
};

#endif

