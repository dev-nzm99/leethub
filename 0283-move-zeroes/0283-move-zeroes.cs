public class Solution {
    public void MoveZeroes(int[] nums) {
        int n = nums.Length;
        int i = 0;  
        for(int j = 0; j < n;++j){
            if(nums[j] != 0){
                nums[i++] = nums[j];
            }
        }
        while(i<n){
            nums[i++] = 0;
        }
        return ;
    }
}