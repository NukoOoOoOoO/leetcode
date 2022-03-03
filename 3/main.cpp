#include <iostream>
#include <string>
#include <unordered_set>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int result = 0;
        int l      = 0;
        int length = s.length();

        std::unordered_set<char> set;
        for (auto i = 0; i < length; i++)
        {
            // finding all duplicated character in set
            while (set.find(s[i]) != set.end())
            {
                // delete it from the character
                set.erase(s[l]);
                // update our left window position
                l++;
            }

            set.emplace(s[i]);
            result = std::max(result, i - l + 1);
        }

        return result;
    }
};

int main()
{
    Solution s;

    std::cout << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << s.lengthOfLongestSubstring("pwwkew") << std::endl;

    return 0;
}