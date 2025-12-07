/*
 Author:Nazmul Islam
 Using binary search
 Complexity: O(logn) & O(1)
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;
        int res = 0;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (mid > 0 && nums[mid] > nums[mid - 1]) {
                res = mid;
                st = mid + 1;
            } else {
                if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                  //  res = mid;
                    end = mid - 1;
                } else
                    st = mid + 1;
            }
        }
        return res;
    }
};