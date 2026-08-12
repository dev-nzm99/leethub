public class Solution {
    public int[] TwoSum(int[] numbers, int target) {
        int[] res = new int[2];
        int n = numbers.Length;
        int i = 0,j = n-1;
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                res[0] = i+1;
                res[1] = j+1;
                break;
            }
            if(target > sum)
               i++;
            else
               j--;
        }
        return res;
    }
}