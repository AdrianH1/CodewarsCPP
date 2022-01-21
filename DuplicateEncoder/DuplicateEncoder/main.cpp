#include <string>
#include <iostream>
#include <map>
#include <cctype>

std::string duplicate_encoder(const std::string& word) {
	int count = 0;
	std::string res;
	for (char c : word)
	{
		for (char d : word)
		{
			if (tolower(d) == tolower(c))
				count++;
		}
		if (count == 1)
			res.append("(");
		else
			res.append(")");
		count = 0;
	}
	return res;
}

std::string Solutionduplicate_encoder(const std::string& word)
{
	std::map<char, int> counter;
	std::string s{ "" };
	for (char c : word)
	{
		counter[std::tolower(c)] += 1;
	}

	for (char c : word)
	{
		s += counter[std::tolower(c)] > 1 ? ")" : "(";
	}
	return s;
}

int main()
{
	std::cout << duplicate_encoder("din") << std::endl; // ("((("));
	std::cout << duplicate_encoder("recede") << std::endl; // ("()()()"));
	std::cout << duplicate_encoder("Success") << std::endl; // (")())())"));
	std::cout << duplicate_encoder("CodeWarrior") << std::endl; // ("()(((())())"));
	std::cout << duplicate_encoder("Supralapsarian") << std::endl; // (")()))()))))()("));
	return 0;
}
