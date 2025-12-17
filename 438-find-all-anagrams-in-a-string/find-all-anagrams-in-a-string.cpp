/*
 Author: Nazmul Islam
 Using sliding window + freq array
 Complexity: O(n) time & O(1) space (fixed size array)
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int windSize = p.size();

        vector<int> freq(26, 0), windFreq(26, 0);
        vector<int> res;
        if (n < windSize)
            return res;

        for (const auto& c : p)
            ++freq[c - 'a'];
        // Set window
        for (int i = 0; i < windSize; ++i) 
            ++windFreq[s[i] - 'a'];

        if (Check(freq, windFreq)) 
            res.push_back(0);

        // Slide window
        for (int i = windSize; i < n; ++i) {
            ++windFreq[s[i] - 'a'];
            --windFreq[s[i - windSize] - 'a'];
            if (Check(freq, windFreq))
                res.push_back(i - windSize + 1);
        }
        return res;
    }

private:
    bool Check(vector<int>& freq1, vector<int>& freq2) {
        for (int i = 0; i < freq1.size(); ++i)
            if (freq1[i] != freq2[i])
                return false;
        return true;
    }
};