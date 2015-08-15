import java.util.Hashtable;
public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] ans = new int[2];
        Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();
        for(int i = 0; i < numbers.length; i++){
            Integer tmp = ht.get(target-numbers[i]);
            if(tmp != null){
                ans[0] = tmp>i?i+1:tmp+1;
                ans[1] = tmp>i?tmp+1:i+1;
                return ans;
            }
            Integer n = ht.get(numbers[i]);
            if(n == null) ht.put(numbers[i], i);
        }
        return ans;
    }
}