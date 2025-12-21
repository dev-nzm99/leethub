/*
 Author:Nazmul Islam
 Using Binary Search
 Complexity: O(logn) and O(1)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int L = 0, R = n - 1;
        vector<int> res(2, -1);
        // To find first position
        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (arr[mid] == target) {
                res[0] = mid;
                R = mid - 1;
            } else if (arr[mid] < target)
                L = mid + 1;
            else
                R = mid - 1;
        }
        // To find last position
        R = n - 1;
        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (arr[mid] == target) {
                res[1] = mid;
                L = mid + 1;
            } else if (arr[mid] < target)
                L = mid + 1;
            else
                R = mid - 1;
        }
        return res;
    }
};