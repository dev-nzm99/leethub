/*
  Author:Nazmul Islam
  Complexity: O(logn) time & O(1) space
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0;
        int r = arr.size() - 1;
        int res = arr.size();  //for edge cases
        while (l <= r) {
            int m = l + (r - l) / 2;
            if ((arr[m] - m - 1) >= k) {
                res = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res + k;
    }
};