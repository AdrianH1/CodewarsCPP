#include <vector>
#include <iostream>

std::vector < int> josephus(std::vector < int > items, int k) {
    std::vector<int> result;
    for (int i = k; items.size() > 0; i += (k-1))
    {
        while (i > items.size())
            i = i - items.size();
        result.push_back(items.at(i-1));
        items.erase(items.begin() + (i - 1));

    }
    return result;
}

std::vector <int> otherSolutionJosephus(std::vector <int> items, int k) {
    std::vector< int > result;
    int pos = k - 1;

    while (items.size())
    {
        pos %= items.size();
        result.push_back(items[pos]);
        items.erase(items.begin() + pos);
        pos += k - 1;
    }

    return result;
}


int main()
{
    josephus({ 1, 2, 3, 4, 5, 6, 7 }, 3);//, Equals(std::vector < int >({ 3,6,2,7,5,1,4 })));
    josephus({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 1);//, Equals(std::vector < int >({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 })));
    josephus({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 2);//, Equals(std::vector < int >({ 2, 4, 6, 8, 10, 3, 7, 1, 9, 5 })));
    josephus({ 1, 2, 3, 4, 5, 6, 7 }, 3);//, Equals(std::vector < int >({ 3, 6, 2, 7, 5, 1, 4 })));
    josephus({}, 3);//, Equals(std::vector < int >({})));
}