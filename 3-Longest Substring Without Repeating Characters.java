public class Solution {
    public int lengthOfLongestSubstring(String s) {
        boolean[] flag = new boolean[256];
        int result = 0;
        int start = 0;
        for(int i = 0; i < s.length(); i++){
             char p = s.charAt(i);
             if(flag[p]){
                 result = Math.max(result, i-start);
                 for(int j = start; j < i; j++){
                     if(s.charAt(j) == p){
                         start = j+1;
                         break;
                     }
                     flag[s.charAt(j)] = false;
                 }
             }else{
                 flag[p] = true;
             }
        }
        return Math.max(result, s.length()-start);
    }
}