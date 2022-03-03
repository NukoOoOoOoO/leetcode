#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        if (nums1.size() + nums2.size() == 1)
            return nums1.size() == 0 ? nums2[0] : nums1[0];

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        int size = nums1.size();

        if (size % 2 == 1)
        {
            std::nth_element(nums1.begin(), nums1.begin() + size / 2, nums1.end());
            return nums1[size / 2];
        }

        std::nth_element(nums1.begin(), nums1.begin() + size / 2, nums1.end());
        auto a = nums1[size / 2];
        std::nth_element(nums1.begin(), nums1.begin() + size / 2 - 1, nums1.end());
        auto b = nums1[size / 2 - 1];
        return (a + b) / 2.0;
    }
};

int main()
{
    Solution s;
    std::vector<int> vec1 { 1, 3 }, vec2 { 2 }, vec3 { 1, 2 }, vec4 { 3, 4 };
    std::cout << s.findMedianSortedArrays(vec1, vec2) << std::endl;
    std::cout << s.findMedianSortedArrays(vec3, vec4) << std::endl;
}