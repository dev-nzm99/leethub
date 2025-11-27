/*
  Author:Nazmul Islam
  Created: 2025-11-22 21:30
  Using prefix sum + Hash map
  O(n) time & O(n) space
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m;
        int res = 0;
        int prefixTracker = 0;
        m[0]++;
        for (int i = 0; i < nums.size(); ++i) {
            prefixTracker += nums[i];
            if (m.find(prefixTracker - goal) != m.end())
                res += m[prefixTracker - goal];
            m[prefixTracker]++;
        }
        return res;
    }
};

/*
  //Using Sliding window
  //O(n) time & O(1) space (space optimization)
--------------------------------------------------------------------------
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return halperFun(nums, goal) - halperFun(nums, goal - 1);
    }
private:
   //helper function to calculate the number of subarrays with sum <= k
    int halperFun(vector<int>& arr, int k) {  
        if (k < 0)
            return 0;
        int cnt = 0;
        int l = 0;
        int sum = 0;
        for (int r = 0; r < arr.size(); ++r) {
            sum += arr[r];
            while (sum > k) {
                sum -= arr[l];
                ++l;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
};
*/
