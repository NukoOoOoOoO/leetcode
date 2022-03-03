#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> map;

        for (auto i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i]) && std::abs(map[nums[i]] - i) <= k)
                return true;

            map[nums[i]] = i;
        }

        return false;
    }
};

int main()
{
    Solution s;

    std::vector<int> vec1{1,2,3,1};
    std::cout << s.containsNearbyDuplicate(vec1, 3) << std::endl;

    std::vector<int> vec2{1,0,1,1};
    std::cout << s.containsNearbyDuplicate(vec2, 1) << std::endl;

    std::vector<int> vec3{1,2,3,1,2,3};
    std::cout << s.containsNearbyDuplicate(vec3, 2) << std::endl;
}