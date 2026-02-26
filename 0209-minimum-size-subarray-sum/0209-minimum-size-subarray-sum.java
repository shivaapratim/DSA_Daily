class Solution {
    public int minSubArrayLen(int k, int[] nums) {
        
        int n=nums.length;
        int head = -1;  
        int tail = 0;
        int ans = 1000000;
        int sum = 0;
       

        while (tail < n) {
            while (head + 1 < n && ((sum) < k)) { 
                head++;
                sum+=nums[head];
            }
            if(sum >= k){
                ans = Math.min(ans, (head - tail + 1));
            }

            if (tail <= head) {
                sum-=nums[tail];
                tail++;
            } 
            else if (tail > head) {
                tail++;
                head = tail - 1;   
            }

        }

        return ans==1000000 ? 0 : ans;

    }
}