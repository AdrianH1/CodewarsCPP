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

    long long l = n;
    while (l > 0)
    {
        v.push_back(l % 10);
        l = l / 10;
    }

    int swap = 0;
    bool shouldSwap = false;
    for (int i = 0; i < v.size()-1; i++)
    {
        if (v[i] > v[i + 1])
        {
            int tmp = v[i];
            int tmpPos = 0;
            for (int j = i; j >= 0; j--)
            {
                if (v[j] < v[i] && v[j] > v[i + 1])
                {
                    if (v[j] < tmp)
                    {
                        tmp = v[j];
                        tmpPos = j;
                        shouldSwap = true;
                    }
                }
                if (j == 0 && shouldSwap)
                {
                    std::swap(v[tmpPos], v[i + 1]);
                    swap++;
                }
            }
            if (!shouldSwap)
            {
                std::swap(v[i], v[i + 1]);
            }
            std::reverse(v.begin(), v.end());
            std::sort(v.begin() + (v.size() - i - 1), v.end());
            break;
        }
    }

    long long result = 0;
    long long multi = 1;
    for (int i = v.size()-1; i >= 0; i--)
    {
        result = result + (v[i] * multi);
        multi = multi * 10;
    }
    
    std::cout << result << std::endl;
    
    if (result < n || result == n)
        return -1;
    return result;
}

/*
9150573627176598864
9150573627176645889

9150573627176845689
*/


int main()
{
    nextBigger(12); //, Equals(21));

    nextBigger(9150573627176598864); //9150573627176645889

    nextBigger(9876543210); //-1

    nextBigger(865139520646570142); //865139520646570214

    nextBigger(1618230024584763531); //1618230024584765133
    nextBigger(7765668451209933966); //7765668451209936369
    nextBigger(7478998885544432211); //7479112234445588889

    nextBigger(4805108411551276844); //4805108411551278446
    nextBigger(5517999888765544422); //5518224445567788999

    nextBigger(563811); //568113
    nextBigger(513); //, Equals(531));
    nextBigger(2017); //, Equals(2071));
    nextBigger(414); //, Equals(441));
    nextBigger(144); //, Equals(414));
    nextBigger(10990); //, Equals(19009));
}

