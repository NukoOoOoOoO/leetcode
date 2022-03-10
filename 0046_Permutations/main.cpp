#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
    std::vector<std::vector<int>> _result;
    std::vector<int> _temp;

    void backtracking(std::vector<int>& nums, int index)
    {
        int length = nums.size();

        if (index == length)
        {
            _result.push_back(_temp);
            return;
        }

        for (auto i = 0; i < length; i++)
        {
            if (std::find(_temp.begin(), _temp.end(), nums[i]) != _temp.end())
                continue;

            _temp.push_back(nums[i]);
            backtracking(nums, index + 1);
            _temp.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        _result.clear();
        _temp.clear();
        backtracking(nums, 0);
        return _result;
    }
};

int main()
{
    Solution s;

    std::vector<int> nums = { 1, 2, 3 };
    auto result           = s.permute(nums);

    auto print = [&]()
    {
        std::cout << "[ ";
        for (const auto& i : result)
        {
            std::cout << "[ ";
            for (auto j = 0; j < i.size(); j++)
            {
                std::cout << i[j] << " ";
            }
            std::cout << "] ";
        }
        std::cout << "]" << std::endl;
    };
    print();

    nums   = { 0, 1 };
    result = s.permute(nums);
    print();

    nums   = { 0 };
    result = s.permute(nums);
    print();
}