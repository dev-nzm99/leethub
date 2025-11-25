/*
 Author:Nazmul Islam
 Created: 2025-11-25 21:53
 Using Prefix sum + hash map
 Complexity: O(n) time & O(n) space
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int prefixSum = 0;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += (nums[i] == 0) ? -1 : nums[i];

            if (prefixSum == 0)
                maxLen = i + 1;
            else if (m.find(prefixSum) != m.end())
                maxLen = max(maxLen, i - m[prefixSum]);

            if (m.find(prefixSum) == m.end())
                m[prefixSum] = i;
        }
        return maxLen;
    }
};