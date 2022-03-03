#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::unordered_map<int, int> map;
        for (auto i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i]))
                return true;
            map[nums[i]] = i;
        }

        // std::sort(nums.begin(), nums.end());
        // int last = INT_MIN;
        // for (auto&& i : nums)
        // {
        //     if (i == last)
        //         return true;
        //     last = i;
        // }

        // return false;
    }
};

int main()
{
    Solution s;

    std::vector<int> vec1 { 1, 2, 3, 1 };
    std::cout << s.containsDuplicate(vec1) << std::endl;

    std::vector<int> vec2 { 1, 2, 3, 4 };
    std::cout << s.containsDuplicate(vec2) << std::endl;

    std::vector<int> vec3 { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
    std::cout << s.containsDuplicate(vec3) << std::endl;
}