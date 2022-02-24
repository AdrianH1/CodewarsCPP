#include <iostream>
#include <vector>

int score(const std::vector<int>& dice) {
	int finalScore = 0;

	for (int i = 1; i <= 6; i++)
	{
		int diceCount = count(dice.begin(), dice.end(), i);
		switch (diceCount)
		{
		case 1:
			if (i == 1)
				finalScore += 100;
			if (i == 5)
				finalScore += 50;
			break;
		case 2:
			if (i == 1)
				finalScore += 200;
			if (i == 5)
				finalScore += 100;
			break;
		case 3:
			if (i == 1)
				finalScore += 1000;
			else
				finalScore += i * 100;
			break;
		case 4:
			if (i == 1)
				finalScore += 1100;
			else if (i == 5)
				finalScore += 550;
			else
				finalScore += i * 100;
			break;
		case 5:
			if (i == 1)
				finalScore += 1200;
			else if (i == 5)
				finalScore += 600;
			else
				finalScore += i * 100;
			break;
		default:
			break;
		}
	}
	return finalScore;

}

int SolutionScore(const std::vector<int>& dice)
{
	int score = 0;
	int count[7] = { 0 };
	for (auto v : dice)
		if (++count[v] == 3)
		{
			score += (v == 1) ? 1000 : v * 100;
			count[v] = 0;
		}
	score += count[1] * 100;
	score += count[5] * 50;
	return score;
}

int main()
{
	score({ 6,6,6,3,3 }); // equal 500
	score({ 4,4,4,1,4 }); // equal 500
	score({ 3,3,3,3,3 }); // equal 300
	score({ 2,3,4,6,2 }); // equal 0
	score({ 2,4,4,5,4 }); // equal 450
	score({ 2,1,1,1,1 }); // equal 1100
	score({ 5,5,5,5,1 }); // equal 650

	SolutionScore({ 6,6,6,3,3 }); // equal 500
	SolutionScore({ 4,4,4,1,4 }); // equal 500
	SolutionScore({ 3,3,3,3,3 }); // equal 300
	SolutionScore({ 2,3,4,6,2 }); // equal 0
	SolutionScore({ 2,4,4,5,4 }); // equal 450
	SolutionScore({ 2,1,1,1,1 }); // equal 1100
	SolutionScore({ 5,5,5,5,1 }); // equal 650
}


// Rules
// Three 1's => 1000 points
// Three 6's =>  600 points
// Three 5's =>  500 points
// Three 4's =>  400 points
// Three 3's =>  300 points
// Three 2's =>  200 points
// One   1 = > 100 points
// One   5 = > 50 point