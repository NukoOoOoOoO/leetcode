#include <iostream>
#include <string>

class Solution
{
public:
    int lengthOfLastWord(std::string str)
    {
        std::string b;
        size_t last = 0;
        size_t next;

        while ((next = str.find(' ', last)) != std::string::npos)
        {
            if (auto s = str.substr(last, next - last); !s.empty())
                b = s;
            last = next + 1;
        }

        if (const auto s = str.substr(last); !s.empty())
            b = s;

        return b.size();
    }
};

int main()
{
    Solution s;
    std::cout << s.lengthOfLastWord("Hello World") << std::endl;
    std::cout << s.lengthOfLastWord("   fly me   to   the moon  ") << std::endl;
    std::cout << s.lengthOfLastWord("luffy is still joyboy") << std::endl;
    return 0;
}