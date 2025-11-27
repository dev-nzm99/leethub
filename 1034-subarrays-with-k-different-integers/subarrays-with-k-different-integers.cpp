/*
  Author:Nazmul Islam
  submitted at Nov 27, 2025 15:02
  Using sliding window
  Complexity: O(n) time & O(n) space
*/
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helperFunction(nums, k) - helperFunction(nums, k - 1);
    }

private:
    // to calculate the number of subarrays with at most k different integers
    int helperFunction(vector<int>& a, int v) {
        if (v < 0) return 0;
        unordered_map<int, int> m;
        int l = 0;
        int cnt = 0;
        for (int r = 0; r < a.size(); ++r) {
            ++m[a[r]];
            while (m.size() > v) {
                if (--m[a[l]] == 0)
                    m.erase(a[l]);
                ++l;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
};
