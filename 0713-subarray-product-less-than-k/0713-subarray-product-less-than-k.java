class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {

        int n=nums.length;
        int head = -1;  
        int tail = 0;
        int ans = 0;
        int prod = 1;
       

        while (tail < n) {
            while (head + 1 < n && ((prod *  nums[head + 1]) < k)) { 
                head++;
                prod*=nums[head];
            }
            ans += (head - tail + 1);

            if (tail <= head) {
                prod/=nums[tail];
                tail++;
            } 
            else if (tail > head) {
                tail++;
                head = tail - 1;   
            }

        }

        return ans;

    }
}