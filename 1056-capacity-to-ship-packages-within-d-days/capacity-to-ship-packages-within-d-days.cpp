/*
  Author:Nazmul Islam
  Using Answer on Binary Search Pattern
  Complexity: 
*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = 0;
        int maxCap = 0;
        for (const auto& weight : weights) {
            minCap = max(minCap, weight);
            maxCap += weight;
        }
        int leastWeight = 0;
        while (minCap <= maxCap) {
            int mid = minCap + (maxCap - minCap) / 2;
            if (capShip(mid, weights, days)) {
                maxCap = mid - 1;
            } else {
                minCap = mid + 1;
            }
        }
        return minCap;
    }
private:
    bool capShip(int capacity, vector<int>& weights, int days) {
        int dayCnt = 1;
        int sum = 0;
        for (const auto& weight : weights) {
            if (sum + weight > capacity) {
                ++dayCnt;
                sum = 0;
            }
            sum += weight;
        }
        return dayCnt <= days;
    }
};