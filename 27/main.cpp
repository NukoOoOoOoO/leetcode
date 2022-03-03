#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        for (auto it = nums.begin(); it != nums.end();)
        {
            if (*it == val)
                it = nums.erase(it);
            else
                ++it;
        }

        return nums.size();
    }
};

int main()
{
    Solution s;

    std::vector<int> vec1{3,2,2,3}; int num1 = 3;
    std::cout << s.removeElement(vec1, num1) << std::endl;

    std::vector<int> vec2{0,1,2,2,3,0,4,2}; int num2 = 2;
    std::cout << s.removeElement(vec2, num2) << std::endl;
}