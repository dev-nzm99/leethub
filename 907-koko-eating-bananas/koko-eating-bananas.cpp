class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k_min = 1;
        int k_max = *max_element(piles.begin(), piles.end());
        while (k_min <= k_max) {
            int mid = k_min + (k_max - k_min) / 2;
            if (canEat(piles, mid, h)) {
                k_max = mid - 1;
            } else
                k_min = mid + 1;
        }
        return k_min;
    }
private:
    bool canEat(vector<int>& piles, int k, int h) {
        long long totalHour = 0.0;
        for (const auto& pile : piles) {
            totalHour += ceil((double)pile / k);
        }
        return totalHour <= h;
    }
};