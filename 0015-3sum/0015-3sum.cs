public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        IList<IList<int>> res = new List<IList<int>>();
        Array.Sort(nums);
        int n = nums.Length;
        for(int i = 0; i<n-2 ; i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int fixVal = nums[i];
            int j = i+1, k = n-1;
            
            while(j < k){
                int sum = fixVal + nums[j] + nums[k];
                if( sum == 0 ){
                    res.Add(new List<int> {fixVal, nums[j], nums[k]});
                    j++;k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                }else if(sum > 0)
                    k--;
                else
                    j++; 
            }
        }
        return res;
    }
}