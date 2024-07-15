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

// Checks if the passed strings are a permutation of each other
// Time/Space complexity O(n)
bool arePermutations(string s1, string s2)
{
    // A permutation is a string with the same characters in different order.
    // This means they have got the same length and the same character frequency

    if (s1.length() != s2.length())
        return false;

    // We create a map that first of all counts the letters in the first string, then
    // removes the frequencies throught the second string

    vector<int> map(26, 0); // Lowercase english letters

    // Adds frequencies
    for (auto c : s1)
        map[c - 'a'] ++; // The position is based on the letter value padded from the first alphabet letter

    // Removes frequencies
    for (auto c : s2)
    {
        map[c - 'a'] --;
        // Because strings on the same length, when a letter is different, it must take some place < 0 
        // also if the same character is not in the first string
        if (map[c - 'a'] < 0) 
            return false;
    }

    return true;
}

int numOfChars(char str[], int strLength, char target)
{
    int count = 0;
    for (int i = 0; i < strLength; i ++)
        if (str[i] == target) count ++;

    return count;
}

// Replaces the string's whitespaces with the combination '%20'
// Suppose str has already room for the final string
void replaceWhitspace(char str[], int initialLength)
{
    // Count num whitespace in order to get the new index because we perform backward
    const int numWhitespaces = numOfChars(str, initialLength, ' ');

    // Compute new index from new string length. The new whitespace code is 3 times a whitespace:
    int newIndex = initialLength - numWhitespaces + numWhitespaces * 3 - 1;
    int index = initialLength - 1;
    while (newIndex > 0)
    {
        if (str[index] == ' ')  // Replace whitespace
        {
            str[newIndex] = '0';
            str[newIndex - 1] = '2';
            str[newIndex - 2] = '%';
            newIndex -= 3;
        }
        else // Copy character
        {
            str[newIndex] = str[index];
            newIndex --;
        }
        index --;
    }

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

    vector<string> stringDataset2(6, "");
    stringDataset2[0] = "aaa";
    stringDataset2[1] = "bca";
    stringDataset2[2] = "baccb";
    stringDataset2[3] = "defabc";
    stringDataset2[4] = "ggffaddhh";
    stringDataset2[5] = "gnbvdntyuyggg";

    std::cout << std::boolalpha;  

    for (auto s : stringDataset)
    {
        std::cout << "Input: " << s << " -- Result: " << isUniqueChars(s) << std::endl;
    }

    for (int i = 0; i < stringDataset.size(); i ++)
    {
        std::cout << "Input1: " << stringDataset[i] << " -- Input2: " << stringDataset2[i] << " -- Result: " << arePermutations(stringDataset[i], stringDataset2[i]) << std::endl;
    }

    char replaceInput[] = "Hi, how are you?";
    std::cout << "Replace: " << replaceInput << std::endl;
    replaceWhitspace(replaceInput, sizeof(replaceInput)/sizeof(char));
    std::cout << "Result: " << replaceInput << std::endl;

    return 0;
}