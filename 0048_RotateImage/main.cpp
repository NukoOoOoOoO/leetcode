#include <iostream>
#include <vector>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>>& matrix)
    {
        int l = 0;
        int r = matrix.size() - 1;

        while (l < r)
        {
            for (auto i = 0; i < (r - l); i++)
            {
                auto top = l, bottom = r;

                // saving the top left value
                auto top_left = matrix[top][l + i];

                // moving bottom left -> top left
                matrix[top][l + i] = matrix[bottom - i][l];
                // moving bottom right -> bottom left
                matrix[bottom - i][l] = matrix[bottom][r - i];
                // moving top right to bottom right
                matrix[bottom][r - i] = matrix[top + i][r];
                // moving top left to top right
                matrix[top + i][r] = top_left;
            }
            // As we finish moving one row then we move to next one
            l++;
            r--;
        }
    }
};
