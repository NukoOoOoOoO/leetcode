#include <iostream>

class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0 || x <= INT_MIN || x >= INT_MAX)
            return 0;

        int64_t rev_number = 0;
        while (x)
        {
            rev_number = rev_number * 10 + x % 10;
            if (rev_number <= INT_MIN || rev_number >= INT_MAX)
                return 0;
            x /= 10;
        }

        return rev_number;
    }
};

int main()
{
    Solution s;
    std::cout << s.reverse(123) << std::endl;
    std::cout << s.reverse(-123) << std::endl;
    std::cout << s.reverse(120) << std::endl;
    std::cout << s.reverse(0) << std::endl;
}