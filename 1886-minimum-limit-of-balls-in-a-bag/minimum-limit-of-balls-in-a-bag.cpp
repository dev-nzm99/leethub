/*
 Author:Nazmul Islam
 Using binary search pattern (On answer/conditions)
 Complexity: O(nlogn) time & O(1) space
*/
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int L = 1; 
        int R = *max_element(nums.begin(), nums.end());
        while (L < R) {
            int mid = L + (R - L) / 2;
            if (isPossible(nums, mid, maxOperations))
                R = mid;
            else
                L = mid + 1;
        }
        return L;
    }

private:
    bool isPossible(vector<int>& bags, int panalty, int maxOp) {
        int opCnt = 0;
        for (const auto& balls : bags)
            opCnt += (balls - 1) / panalty;
        return opCnt <= maxOp;
    }
};