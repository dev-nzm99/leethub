/*
 Author:Nazuml Islam
 Using binary search pattern(on answer/condition)
 Complexity O(nlogn) time & O(1) space
*/
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size())
            return -1;
        int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());
        while (minDay < maxDay) {
            int mid = minDay + (maxDay - minDay) / 2;
            if (canMakeBouq(bloomDay, mid, m, k))
                maxDay = mid;
            else
                minDay = mid + 1;
        }
        return minDay;
    }

private:
    bool canMakeBouq(vector<int>& bloomDay, int mid, int m, int k) {
        int bouq = 0;
        int flow = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
            (bloomDay[i] > mid) ? flow = 0 : ++flow;
            if (flow >= k) {
                ++bouq;
                flow = 0;
            }
        }
        return bouq >= m;
    }
};