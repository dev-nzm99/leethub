/*
 Author:Nazmul Islam
 Using binary search pattern(On answer/conditons)
 complexity: O(nlogn) & O(1)
*/
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long totalCandies = 0;
        for (const auto& x : candies)
            totalCandies += x;
        if (totalCandies < k)
            return 0;
        long long L = 1;
        long long R = *max_element(candies.begin(), candies.end());
        int res = 0;
        while (L <= R) {
            long long mid = L + (R - L) / 2;
            if (isFeasible(candies, mid, k)) {
                res = mid;
                L = mid + 1;
            } else
                R = mid - 1;
        }
        return res;
    }

private:
    bool isFeasible(vector<int>& candies, long long m, long long k) {
        long long cnt = 0;
        for (const auto& candie : candies)
            cnt += candie / m;
        return cnt >= k;
    }
};