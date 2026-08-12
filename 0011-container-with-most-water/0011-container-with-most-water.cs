public class Solution {
    public int MaxArea(int[] height) {
        int n = height.Length;
        int i = 0, j = n-1;
        int maxWaterContain = 0;

        while(i < j){
            int waterContain = Math.Min(height[i],height[j]) * (j-i);
            maxWaterContain = Math.Max(maxWaterContain, waterContain);

            if(height[i] <= height[j]) i++;
            else j--;
        }
        return maxWaterContain;
    }
}