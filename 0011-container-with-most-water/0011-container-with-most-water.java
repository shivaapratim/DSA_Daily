class Solution {
    public int maxArea(int[] height) {
        int n= height.length;
        int head=n-1;
        int tail=0;
        int ans=0;

        while(tail<head){
            ans= Math.max(ans, Math.min(height[tail], height[head]) * (head - tail) );

            if(height[head]<height[tail]){
                head--;
            }    
            else{
                tail++;
            }
        }
        return ans;
    }
}