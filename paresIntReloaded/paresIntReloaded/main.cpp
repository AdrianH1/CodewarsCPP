#include <iostream>
#include <string>
#include <map>
#include <vector>

long parse_int(std::string number) {
	std::map<std::string, int> value;
	std::map<std::string, int> multiply;
	value.insert({"one", 1});
	value.insert({"two", 2});
	value.insert({"three", 3});
	value.insert({"four", 4});
	value.insert({"five", 5});
	value.insert({"six", 6});
	value.insert({"seven", 7});
	value.insert({"eight", 8});
	value.insert({"nine", 9});
	value.insert({"ten", 10});
	value.insert({"eleven", 11});
	value.insert({"twelve", 12});
	value.insert({"thirteen", 13});
	value.insert({"fourteen", 14});
	value.insert({"fifteen", 15});
	value.insert({"sixteen", 16});
	value.insert({"seventeen", 17});
	value.insert({"eighteen", 18});
	value.insert({"nineteen", 19});
	value.insert({"twenty", 20});
	value.insert({"thirty", 30});
	value.insert({"forty", 40});
	value.insert({"fifty", 50});
	value.insert({"sixty", 60});
	value.insert({"seventy", 70});
	value.insert({"eighty", 80});
	value.insert({"ninety", 90});
	multiply.insert({"hundred", 100});
	multiply.insert({"thousand", 1000});
	multiply.insert({"million", 1000000});

	std::string word = "";
	std::vector<std::string> numbers;
	int result = 0;
	for (char c : number)
	{
		if (c == ' ' || c == '-')
		{
			if (word != "and")
				numbers.push_back(word);
			word = "";
		}
		else
			word = word + c;
	}
	numbers.push_back(word);

	for (int i = 0; i < numbers.size(); i++)
	{
		if (value[numbers.at(i)])
			result += value[numbers.at(i)];
		else if (multiply[numbers.at(i)])
		{
			if (numbers.at(i) == "thousand" || numbers.at(i) == "million")
				result = (result * multiply[numbers.at(i)]);
			if (numbers.at(i) == "hundred")
				result += (multiply[numbers.at(i)] * value[numbers.at(i - 1)]) - value[numbers.at(i-1)];
		}
	}

	return result;
}


int main()
{
	parse_int("one"); // Equals(1));
	parse_int("ten"); // Equals(10));
	parse_int("twenty"); // Equals(20));
	parse_int("ninety-three"); // Equals(93));
	parse_int("two hundred and forty-six"); // Equals(246));
	parse_int("three thousand and ninty-seven"); // Equals(3097));
	parse_int("twelve thousand six hundred and thirty-two"); // Equals(12632));
	parse_int("five hundred forty-five thousand eight hundred and twenty-nine"); // Equals(545829));
	parse_int("one million"); // Equals(1000000));
}