class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), k = t.length();

        if(n<k)return "";

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
                    if (total > 0)
                        break;
                    int subStrLen = r - l;
                    if (subStrLen < resultStrInx[1] - resultStrInx[0]) {
                        resultStrInx[0] = l;
                        resultStrInx[1] = r;
                    }
                    if (m.contains(s[l]) && m[s[l]] >= 0) {
                        ++total;
                    }
                    ++m[s[l]];
                    ++l;
                }
            }
        }
        return (resultStrInx[1] >= n)? "": s.substr(resultStrInx[0], resultStrInx[1] - resultStrInx[0] + 1);
    }
};