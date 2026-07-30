public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int read,write;
        int n = nums.Length;
        write = 0;
        for(read = 0; read < n ;++read){
            if(nums[read] != val){
                nums[write++] = nums[read];
            }
        }
        return write;
    }
}