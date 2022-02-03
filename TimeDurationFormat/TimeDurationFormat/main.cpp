#include <iostream>
#include <string>
#include <vector>

std::string format_duration(int seconds) {
    std::vector<int> result;
    std::string output;
    std::string units[] = { "second", "minute", "hour", "day", "year" };
    int loops = 0;
    int rest = 0;

    //Set amount of needed loops or return directly if under 60 seconds
    if (seconds == 0)
    { return "now"; }
    if (seconds == 1)
    { return std::to_string(seconds) + " second"; }
    else if (seconds < 60)
    { return std::to_string(seconds) + " seconds"; }
    else if (seconds >= 60 && seconds < 3600)
    { loops = 1; }
    else if (seconds >= 3600 && seconds < 86400)
    { loops = 2; }
    else if (seconds >= 86400 && seconds < 31536000)
    { loops = 3; }
    else if (seconds >= 31536000)
    { loops = 4; }

    //Calculate different units
    //Amounts stored in vector result
    for (int i = 0; i < loops; i++)
    {
        if (i < 2)
        {
            rest = seconds / 60;
            result.push_back(seconds % 60);
            seconds = rest;
        }
        else if (i == 2) {
            rest = seconds /24;
            result.push_back(seconds % 24);
            seconds = rest;
        }
        else
        {
            rest = seconds / 365;
            result.push_back(seconds % 365);
            seconds = rest;
        }
    }
    if (seconds != 0) { result.push_back(seconds); }
    
    //Write results plus correct unit to output string
    int currUnit = 0;
    std::string tmp;
    bool first = true;
    for (int i = 0; i < result.size(); i++)
    {
        if (result.at(i) != 0)
        {
            tmp = std::to_string(result.at(i)) + " " + units[currUnit];
            if (result.at(i) > 1)
                tmp = tmp + "s";
            if (first && result.size() > i+1)
            {
                tmp = " and " + tmp;
                first = false;
            }
            else if (i != result.size()-1)
                tmp = ", " + tmp;
        }
        output = tmp + output;
        tmp = "";
        currUnit++;
    }
    
     return output;
}

std::string bestPracticeSolution_format_duration(int seconds) {
    if (seconds == 0) return "now";

    std::vector<std::string> times;
    auto add = [&](auto text, auto time) {
        if (time == 0) return;
        times.push_back(std::to_string(time) + text + (time > 1 ? "s" : ""));
    };
    add(" year", seconds / 31536000);
    add(" day", (seconds / 86400) % 365);
    add(" hour", (seconds / 3600) % 24);
    add(" minute", (seconds / 60) % 60);
    add(" second", seconds % 60);

    std::string result = times[0];
    for (auto i = 1; i < times.size() - 1; i++) result.append(", " + times[i]);
    if (times.size() > 1) result.append(" and " + times.back());

    return result;
}

int main() {

    std::cout << std::endl <<format_duration(120);
    std::cout << std::endl <<format_duration(132030240);
    std::cout << std::endl <<format_duration(7210);
    std::cout << std::endl <<format_duration(62);
    std::cout << std::endl <<format_duration(33275230);
    
    std::cout << std::endl <<format_duration(0); // Equals("now"));
    std::cout << std::endl <<format_duration(1); // Equals("1 second"));
    std::cout << std::endl <<format_duration(62); // Equals("1 minute and 2 seconds"));
    std::cout << std::endl <<format_duration(120); // Equals("2 minutes"));
    std::cout << std::endl <<format_duration(3662); // Equals("1 hour, 1 minute and 2 seconds"));
}