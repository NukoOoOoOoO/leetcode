#include <iostream>
#include <string>
#include <cstddef>

class Solution
{
public:
    int myAtoi(std::string s)
    {
        if (s.empty())
            return 0;

        auto len = s.length();

        int64_t sum = 0;

        int start_pos = 0;
        while (s[start_pos] == ' ')
            start_pos++;

        if (start_pos == len)
            return 0;

        int sign = 1;

        if (s[start_pos] == '-')
        {
            sign = -1;
            start_pos++;
        }

        if (s[start_pos] == '+')
        {
            if (sign == -1)
                return sum;
            start_pos++;
        }

        for (auto i = start_pos; i < len; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int number = (s[i] - '0');
                sum        = sum * 10 + number;
                if (sum * sign > INT_MAX)
                    return INT_MAX;
                else if (sum * sign < INT_MIN)
                    return INT_MIN;
            }
            else
            {
                break;
            }
        }
        sum *= sign;
        return sum;
    }
};

int main()
{
    Solution s;
    std::cout << s.myAtoi("42") << std::endl;
    std::cout << s.myAtoi("   -42") << std::endl;
    std::cout << s.myAtoi("4193 with words") << std::endl;
    std::cout << s.myAtoi(" +-4193 with words") << std::endl;
    std::cout << s.myAtoi("0000000-423") << std::endl;
    std::cout << s.myAtoi("0000000+4256.") << std::endl;
    return 0;
}