#include <iostream>
#include <string>
#include <vector>

std::string likes(const std::vector<std::string>& names)
{
    int likes = names.size();
    if (likes == 0)
        return "no one likes this";
    else if (likes == 1)
        return names[0] + " likes this";
    else if (likes == 2)
        return names[0] + " and " + names[1] + " like this";
    else if (likes == 3)
        return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    else if (likes >= 4)
        return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
    return ""; 
}

std::string SwitchSolutionLikes(const std::vector<std::string>& names) {
    switch (names.size()) {
    case 0: return "no one likes this";
    case 1: return names[0] + " likes this";
    case 2: return names[0] + " and " + names[1] + " like this";
    case 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    default: return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
    }
}

int main()
{
    std::cout << std::endl << likes({}); // Equals("no one likes this"));
    std::cout << std::endl << likes({ "Peter" }); // Equals("Peter likes this"));
    std::cout << std::endl << likes({ "Jacob", "Alex" }); // Equals("Jacob and Alex like this"));
    std::cout << std::endl << likes({ "Max", "John", "Mark" }); //, Equals("Max, John and Mark like this"));
    std::cout << std::endl << likes({ "Alex", "Jacob", "Mark", "Max" }); //, Equals("Alex, Jacob and 2 others like this"));

    return 0;
}