/*
 Author:Nazmul Islam
 Using Greedy Pattern
 Complexity: O(n) time & space
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int i = 0, j = 0;

        // Add all non-overlapping intervals
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);

        //Add remaining intervals
        while (i < n) {
            res.push_back(intervals[i++]);
        }
        return res;
    }
};