/*
 Author:Nazmul Islam
 Using binary search pattern
 Complexity: O(logn) time & O(1) space
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (((m & 1) && (nums[m] == nums[m - 1])) ||
                (!(m & 1) && (nums[m] == nums[m + 1])))
                l = m + 1;
            else
                r = m - 1;
        }
        return nums[l];
    }
};