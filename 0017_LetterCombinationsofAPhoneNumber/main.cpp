#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
    std::unordered_map<char, std::string> nums = {
        {'1',  ""    }
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs"},
        { '8', "tuv" },
        { '9', "wxyz"},
    };

    std::vector<std::string> _results {};
    std::string _tempString {};

    void backtracking(const std::string& str, int idx)
    {
        if (idx == str.size())
        {
            _results.push_back(_tempString);
            _results.return;
        }

        auto& letters = nums[str[idx]];

        for (auto i = 0; i < letters.size(); i++)
        {
            _tempString.push_back(letters[i]);
            backtracking(str, idx + 1);
            _tempString.pop_back();
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        _tempString.clear();
        _results.clear();
        if (digits.empty())
            return _results;
        backtracking(digits, 0);
        return _results;
    }
};

int main()
{
    Solution s;

    auto res = s.letterCombinations("23");
    for (auto i : res)
        std::cout << i << " ";
    std::cout << std::endl;

    res = s.letterCombinations("8964");
    for (auto i : res)
        std::cout << i << " ";
    std::cout << std::endl;

    res = s.letterCombinations("1");
    for (auto i : res)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << std::endl;
    res = s.letterCombinations("12");
    for (auto i : res)
        std::cout << i << " ";
    std::cout << std::endl;

    res = s.letterCombinations("2");
    for (auto i : res)
        std::cout << i << " ";
}