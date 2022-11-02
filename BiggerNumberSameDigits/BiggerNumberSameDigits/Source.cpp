#include <vector>
#include <algorithm>
#include <iostream>

void separateDigits(long n, std::vector<int>* separate)
{
    if (n >= 10)
        separateDigits(n / 10, separate);
    separate->push_back(n % 10);
}

long nextBigger(long long n) {
    std::vector<long> v;

    while (n > 0)
    {
        v.push_back(n % 10);
        n = n / 10;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > v[i+1])
        {
            std::swap(v[i], v[i+1]);
            for (int j = i; j >= 1; j--)
            {
                if (v.at(j) > v.at(j - 1))
                {
                    std::swap(v[j], v[j - 1]);
                }
            }
            break;
        }
    }

    long long result = 0;
    long long multi = 1;
    for (long l : v)
    {
        result = result + (l*multi);
        multi = multi * 10;
    }
    
    std::cout << result << std::endl;
    return result;
}

/*
513
531

414
441

10990
19009

75319
75391

563811
568311
568113
*/


int main()
{
    nextBigger(1618230024584763531); //1618230024584765133

    nextBigger(4805108411551276844); //4805108411551278446
    nextBigger(5517999888765544422); //5518224445567788999

    nextBigger(563811); //568113
    nextBigger(12); //, Equals(21));
    nextBigger(513); //, Equals(531));
    nextBigger(2017); //, Equals(2071));
    nextBigger(414); //, Equals(441));
    nextBigger(144); //, Equals(414));
    nextBigger(10990); //, Equals(19009));
}

