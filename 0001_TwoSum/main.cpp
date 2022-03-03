#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i)
        {
            const auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
            {
                return { it->second, i };
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution s;

    std::vector<int> nums { 2, 7, 11, 15 };
    int target              = 9;
    std::vector<int> result = s.twoSum(nums, target);

    for (auto& i : result)
        std::cout << i << " ";
    std::cout << std::endl;

    nums   = { 3, 2, 4 };
    target = 6;
    result = s.twoSum(nums, target);

    for (auto& i : result)
        std::cout << i << " ";
    std::cout << std::endl;

    nums   = { 3, 3 };
    target = 6;
    result = s.twoSum(nums, target);

    for (auto& i : result)
        std::cout << i << " ";
    std::cout << std::endl;
}