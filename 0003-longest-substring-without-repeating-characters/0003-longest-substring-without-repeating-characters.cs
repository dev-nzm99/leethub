public class Solution {
    public int LengthOfLongestSubstring(string s) {
        HashSet<char> hs = new HashSet<char>();
        int n = s.Length;
        int left = 0;
        int maxLen = 0;
        
        for(int right = 0; right < n; ++right){
            while(hs.Contains(s[right]) && left <= right){
                hs.Remove(s[left]);
                left++;
            }
            hs.Add(s[right]);
            maxLen = Math.Max(maxLen, right - left + 1);                   
        }
        return maxLen;
    }
}