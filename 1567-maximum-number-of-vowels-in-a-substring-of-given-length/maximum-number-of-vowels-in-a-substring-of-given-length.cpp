/*
 Author:Nazmul Islam
 Using sliding window pattern
 Complexity: O(n) time & O(1) space
*/
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
        int maxVowelCnt = INT_MIN;
        for (int i = 0, currCnt = 0; i < s.length(); ++i) {
            currCnt += (vowelSet.contains(s[i]));
            if (i >= k) {
                currCnt -= (vowelSet.contains(s[i - k]));
            }
            maxVowelCnt = max(maxVowelCnt, currCnt);
        }
        return maxVowelCnt;
    }
};