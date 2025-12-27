/*
  Author:Nazmul Islam
  Using prefix sum and Hash map
  COmplexity: O(n) time & O(n) Space
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prefixSum(n, 0);
        unordered_map<int, int> m;
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; ++i)
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        int res = 0;
        m[0]++;
        for (int i = 0; i < n; ++i) {
            int remainder = prefixSum[i] % k;
            if (remainder < 0) { // handled nagetive remainder
                remainder += k;
            }
            if (m.contains(remainder))
                res += m[remainder];
            m[remainder]++;
        }
        return res;
    }
};
