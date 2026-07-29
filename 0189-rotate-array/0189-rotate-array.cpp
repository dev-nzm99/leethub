class Solution {
private:
    void revarseArr(vector<int>& arr, int l, int r) {
        while (l < r) {
            swap(arr[l++],arr[r--]);
        }
        return;
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        revarseArr(nums, 0, n - 1);
        revarseArr(nums, 0, k - 1);
        revarseArr(nums, k, n - 1);
        return;
    }
};