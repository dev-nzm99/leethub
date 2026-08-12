public class Solution {
    public int NumRescueBoats(int[] people, int limit) {
        Array.Sort(people);
        int n = people.Length;
        int i = 0,j = n-1;
        int res = 0;

        while(i < j){
            int sum = people[i] + people[j];
            if(sum <= limit){
                i++;j--;
            }else{
                j--;
            }
            res++;
        }
        if(i == j) res++;
        return res;
    }
}