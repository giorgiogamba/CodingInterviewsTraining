// Copyright Giorgio Gamba

#include <iostream>

using namespace std;


// By now, we create a function for every problems and solution we want to create

// Implement and algorithm to check that every character inside a string is unique
bool isUniqueChars(string s1)
{
    // First implementation: assuming ASCII charset, we define a map for every character
    // of the ASCII dataset small (128 characters) and count the number of times every 
    // character appears. If more than one, early false return.

    vector<int> map(128, 0);
    for (auto c : s1)
    {
        map[c - 'a'] ++;
        if (map[c - 'a'] > 1) // Not unique character
            return false;
    }

    return true;
}

int main()
{
    vector<string> stringDataset(6, "");
    stringDataset[0] = "aaa";
    stringDataset[1] = "abc";
    stringDataset[2] = "abbcc";
    stringDataset[3] = "abcdef";
    stringDataset[4] = "agghhffdd";
    stringDataset[5] = "tyuyvdgnbn";

    std::cout << std::boolalpha;  

    for (auto s : stringDataset)
    {
        std::cout << "Input: " << s << " -- Result: " << isUniqueChars(s) << std::endl;
    }

    return 0;
}