/*
 Author:Nazmul Islam
 Complexity: O(n) time & O(1) space
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int zeroCnt = 0, l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            zeroCnt += (nums[r] == 0);
            while (zeroCnt > k) {
                zeroCnt -= (nums[l] == 0);
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
