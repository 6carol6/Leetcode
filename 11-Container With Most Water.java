public class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int l = 0, r = height.length-1;
        while(l < r){
            int contain = height[l]<height[r]?height[l]:height[r];
            contain *= (r-l);
            max = max>contain?max:contain;
            if(height[l] < height[r]){
                int h = height[l];
                while(l<r && height[l]<=h){
                    l++;
                }
                
            }else{
                int h = height[r];
                while(l<r && height[r]<=h){
                    r--;
                }
            }
        }
        
        return max;
    }
}