/*
 Author:Nazmul Islam
 submitted at Nov 28, 2025 22:24
 Using sliding window and hash map
 complexity: O(n+m) time & O(n+m) space
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), k = t.length();

        if (n < k)
            return "";

        unordered_map<char, int> m;
        for (const char& c : t)
            m[c]++;

        int resultStrInx[2] = {0, INT_MAX};
        int l = 0, total = k;
        for (int r = 0; r < n; ++r) {
            if (m.contains(s[r]) && m[s[r]] > 0) {
                --total;
            }
            --m[s[r]];
            if (total == 0) {
                while (true) {
                    if (m.contains(s[l]) && m[s[l]] == 0)
                        break;
                    ++m[s[l]];
                    ++l;
                }
                if (r - l < resultStrInx[1] - resultStrInx[0]) {
                    resultStrInx[0] = l;
                    resultStrInx[1] = r;
                }
                ++m[s[l]];
                ++total;
                ++l;
            }
        }
        return (resultStrInx[1] >= n) ? "" : s.substr(resultStrInx[0], resultStrInx[1] - resultStrInx[0] + 1);
    }
};