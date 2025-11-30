/*
  Author:Nazmul Islam
  submitted at Nov 30, 2025 21:18
  complexity: O(log(row * col)) time & O(1) space
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int l = 0, r = row * col - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int val = matrix[m / col][m % col];
            if (val == target)
                return true;
            else if (val > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
};
