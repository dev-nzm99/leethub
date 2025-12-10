/*
 Author:Nazuml Islam
 Using binary search pattern(on answer)
 Complexity O(Nlogm) time & O(1) space
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = *max_element(piles.begin(), piles.end());
        while (minSpeed < maxSpeed) {
            int mid = minSpeed + (maxSpeed - minSpeed) / 2;
            if (canEat(piles, mid, h)) {
                maxSpeed = mid;
            } else
                minSpeed = mid + 1;
        }
        return minSpeed;
    }

private:
    bool canEat(vector<int>& piles, int k, int h) {
        int totalHour = 0;
        for (const auto& pile : piles) {
            totalHour += (int)ceil((double)pile / k);
        }
        return totalHour <= h;
    }
};