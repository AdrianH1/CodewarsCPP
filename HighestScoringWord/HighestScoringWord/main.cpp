#include <iostream>
#include <string>
#include <sstream>

std::string highestScoringWord(const std::string& str)
{
    std::istringstream ss(str);
    int score = 0;
    int highScore = 0;
    std::string highScoreWord;
    std::string word;
    while (ss >> word)
    {
        for (char c : word)
            score = score + c - 96;
        if (score > highScore)
        {
            highScoreWord = word;
            highScore = score;
        }
        score = 0;
        std::cout << word << "\n";
    }
	return highScoreWord;
}	

int main()
{
    highestScoringWord("man i need a taxi up to ubud"); // Equals("taxi"));
    highestScoringWord("what time are we climbing up the volcano"); // Equals("volcano"));
    highestScoringWord("take me to semynak"); // Equals("semynak"));
    highestScoringWord("massage yes massage yes massage"); // Equals("massage"));
    highestScoringWord("take two bintang and a dance please"); // Equals("bintang"));
    highestScoringWord("aa b"); // Equals("aa"));
	return 0;
}