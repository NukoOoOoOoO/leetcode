#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int sumOfUnique(std::vector<int>& nums)
    {
        int sum = 0;
        std::unordered_map<int, int> map;

        for (auto num : nums)
        {
            map[num]++;
        }

        for (const auto& [k, v] : map)
        {
            if (v == 1)
                sum += k;
        }

        return sum;
    }
};

int main()
{
    Solution s;
    std::cout << s.sumOfUnique({ 1, 2, 3, 2 }) << std::endl;
    std::cout << s.sumOfUnique({ 1, 1, 1, 1, 1 }) << std::endl;
    std::cout << s.sumOfUnique({ 1, 2, 3, 4, 5 }) << std::endl;
}