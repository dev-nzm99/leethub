/*
 Author:Nazmul Islam
 Complexity: O(n) & O(1)
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
             });
        int endInterval = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (endInterval > intervals[i][0]) {
                ++cnt;
                endInterval = min(endInterval, intervals[i][1]);
            } else {
                endInterval = intervals[i][1];
            }
        }
        return cnt;
    }
};