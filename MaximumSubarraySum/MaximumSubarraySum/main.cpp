#include <iostream>
#include <vector>

int maxSequence(const std::vector<int>& arr) {
	if (arr.empty()) { return 0; }
	int subLength = 1;
	int maxNumber = 0;
	for (subLength; subLength <= arr.size(); subLength++)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			int tmpNumber = 0;
			for (int j = 0; j < subLength; j++)
			{
				if (i+j < arr.size())
					tmpNumber += arr.at(i+j);
			}
			if (maxNumber < tmpNumber)
				maxNumber = tmpNumber;
		}
	}
	if (maxNumber > 0)
		return maxNumber;
	else
		return 0;
}

int mSolutionMaxSequence(const std::vector<int>& arr) {
	int localmax = 0;
	int globalmax = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		localmax = localmax + arr[i];
		if (localmax > globalmax)
			globalmax = localmax;
		if (localmax < 0)
			localmax = 0;
	}
	return globalmax;
}

int main()
{
	mSolutionMaxSequence({ -2, 1, -3, 4, -1, 2, 1, -5, 4 }); // Equals(6));
	mSolutionMaxSequence({ 7, 4, 11, -11, 39, 36, 10, -6, 37, -10, -32, 44, -26, -34, 43, 43 }); // Equals(155));
	maxSequence({ 7, 4, 11, -11, 39, 36, 10, -6, 37, -10, -32, 44, -26, -34, 43, 43 }); // Equals(155));
	maxSequence({ -2, 1, -3, 4, -1, 2, 1, -5, 4 }); // Equals(6));
	return 0;
}