#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    int lengthOfLastWord(std::string str)
    {
        str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char s) { return !std::isspace(s); }).base(), str.end());

        int size = str.size();

        int length = 0;

        for (auto i = size - 1; i >= 0; i--)
        {
            if (str[i] != ' ')
                length++;
            else
                break;
        }

        return length;
    }
};

int main()
{
    Solution s;
    std::cout << s.lengthOfLastWord("Hello World") << std::endl;
    std::cout << s.lengthOfLastWord("   fly me   to   the moon  ") << std::endl;
    std::cout << s.lengthOfLastWord("luffy is still joyboy") << std::endl;
    std::cout << s.lengthOfLastWord("a") << std::endl;
    std::cout << s.lengthOfLastWord(" ") << std::endl;
    std::cout << s.lengthOfLastWord("day") << std::endl;
    return 0;
}