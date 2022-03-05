#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.empty())
            return "";

        // sort them as alphabet order
        std::sort(strs.begin(), strs.end());

        // referencing to reduce memory usage :sunglasses:
        auto& left  = strs.front();
        auto& right = strs.back();

        int pos = 0;

        // cases:
        // [sigh, sightly, sight, signal] -> longest prefix is sigh. after sorting [sigh, sight, sightly, signal]
        // the first word and the last word start with the same character, so we keep adding the pos index till both are differnt or one of both reaches to the end of the string

        // ["dog", "cat", "foo", "bar"] -> no longest prefix because after sorting, the order would be ["bar", "cat", "dog", "foo"]
        // the first word and the last word dont even start with same character, so it is safe to ignore
        while (pos < left.size() && right.size() && left[pos] == right[pos])
        {
            pos++;
        }

        return std::string(left.begin(), left.begin() + pos);
    }
};

int main()
{
    Solution s;
    std::vector<std::string> strs = { "flower", "flow", "flight" };
    std::cout << s.longestCommonPrefix(strs) << std::endl;
    strs = { "dog", "racecar", "car" };
    std::cout << s.longestCommonPrefix(strs) << std::endl;
    strs = { "counter", "counterclock", "count", "coun" };
    std::cout << s.longestCommonPrefix(strs) << std::endl;
    strs = { "sigh", "sightly", "sight", "signal" };
    std::cout << s.longestCommonPrefix(strs) << std::endl;
}