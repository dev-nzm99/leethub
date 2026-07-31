public class Solution {
    public void SortColors(int[] nums) {
        int zero, one, two;
        zero = one = two = 0;
        int n = nums.Length;

        for(int i = 0; i< n; ++i){
            if(nums[i] == 0) ++zero;
            else if(nums[i] == 1) ++one;
            else ++two;
        }
        int index = 0;
        while(index< n){
            while(zero>0){
                nums[index++] = 0;
                --zero;
            }
            while(one > 0){
                nums[index++] = 1;
                --one;
            }
            while(two > 0){
                nums[index++] = 2;
                --two;
            }
        }
        return;
    }
}