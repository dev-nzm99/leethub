/*
  Author:Nazmul Islam
  Using Sliding window pattern
  Complexity: O(n) & O(1)
*/
class Solution {
private:
    bool Check(vector<int>& freq1, vector<int>& freq2) {
        for (int i = 0; i < freq1.size(); ++i)
            if (freq1[i] != freq2[i])
                return false;
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int windSize = s1.size();
        int n2 = s2.size();
        if (windSize > n2)
            return false;
        vector<int> freq(26, 0), windFreq(26, 0);
        for (const auto& c : s1)
            ++freq[c - 'a'];
        int i = 0, j = 0;
        while (j < n2) {
            windFreq[s2[j] - 'a']++;
            int len = j - i + 1;
            if (len == windSize && Check(freq, windFreq))
                return true;
            if (len < windSize)
                ++j;
            else {
                windFreq[s2[i] - 'a']--;
                ++j; ++i;
            }
        }
        return false;
    }
};
