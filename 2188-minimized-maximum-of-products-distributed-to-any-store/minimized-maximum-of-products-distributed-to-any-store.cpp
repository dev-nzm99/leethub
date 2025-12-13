/*
 Author:Nazmul Islam
 Using binary search pattern (On answer/conditions)
 Complexity: O(nlogn) time & O(1) space
*/
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int L = 1;
        int R = *max_element(quantities.begin(), quantities.end());
        while (L < R) {
            int mid = L + (R - L) / 2;
            (isPossibleToDistribute(quantities, mid, n)) ? R = mid:   L = mid + 1;
        }
        return L;
    }

private:
    bool isPossibleToDistribute(vector<int>& quantities, int x, int n) {
        int cnt = 0;
        for (const auto& q : quantities)
            cnt += (int)ceil((double)q / x);
        return cnt <= n;
    }
};