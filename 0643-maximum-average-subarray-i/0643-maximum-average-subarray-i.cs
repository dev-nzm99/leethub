public class Solution {
    public double FindMaxAverage(int[] nums, int k) {
        int n = nums.Length;
        double windowSum = 0.0, res  = 0.0;
        
        for(int i = 0; i < k; ++i){
            windowSum += nums[i];
        }
        res = windowSum / k; 
        
        for(int i = k; i < n; ++i){
            windowSum = windowSum - nums[i - k] + nums[i];
            res = Math.Max(windowSum / k, res);  
        }
        return res;
    }
}