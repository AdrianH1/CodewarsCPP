#include <iostream>
#include <vector>
#include <algorithm>

long queueTime(std::vector<int> customers, int n) {
    std::vector<int> tills;
    tills.assign(n, 0);

    for (int i = 0; i < customers.size(); i++)
    {
        std::vector<int>::iterator it = std::min_element(tills.begin(), tills.end());
        int pos = std::distance(tills.begin(), it);
        tills.at(pos) = tills.at(pos) + customers.at(i);
    }

    int maxElement = *std::max_element(tills.begin(), tills.end());
    std::cout << maxElement << std::endl;
    return maxElement;
}

long solutionQueueTime(std::vector<int> customers, int n) {
    std::vector<long> queues(n, 0);

    for (int i : customers)
        *std::min_element(queues.begin(), queues.end()) += i;

    return *std::max_element(queues.cbegin(), queues.cend());
}

int main()
{
    queueTime(std::vector<int>{}, 1); // Equals(0));
    queueTime(std::vector<int>{1, 2, 3, 4}, 1); // Equals(10));
    queueTime(std::vector<int>{2, 2, 3, 3, 4, 4}, 2); // Equals(9));
    queueTime(std::vector<int>{1, 2, 3, 4, 5}, 100); // Equals(5));
	return 0;
}