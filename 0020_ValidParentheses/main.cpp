#include <iostream>
#include <string>
#include <stack>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> stack;
        for (auto&& i : s)
        {
            if (i == '(')
                stack.push(')');
            else if (i == '{')
                stack.push('}');
            else if (i == '[')
                stack.push(']');
            else if (stack.empty() || stack.top() != i)
                return false;
            else
                stack.pop();
        }

        return stack.empty();
    }
};

int main()
{
    Solution s;
    std::cout << s.isValid("()") << std::endl;
    std::cout << s.isValid("()[]{}") << std::endl;
    std::cout << s.isValid("(]") << std::endl;
    std::cout << s.isValid("{[]}") << std::endl;
    return 0;
}