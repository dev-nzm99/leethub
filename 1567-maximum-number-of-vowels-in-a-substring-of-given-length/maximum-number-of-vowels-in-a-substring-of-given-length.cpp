/*
 Author:Nazmul Islam
 Using sliding window pattern
 Complexity: O(n) time & O(1) space 
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            if (vowelSet.contains(s[i])) ++cnt;
        }
        int maxVowelCnt = cnt;
        for (int i = k; i < n; ++i) {
            if (vowelSet.contains(s[i])) ++cnt;
            if (vowelSet.contains(s[i - k])) --cnt;
            maxVowelCnt = max(maxVowelCnt, cnt);
        }
        return maxVowelCnt;
    }
};