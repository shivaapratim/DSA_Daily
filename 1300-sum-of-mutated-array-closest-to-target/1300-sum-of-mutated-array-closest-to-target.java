class Solution {

    public int check(int[] nums, int mid, int target){
        int sum = 0;
        for(int x : nums){
            sum += (x > mid ? mid : x);
        }
        return sum >= target ? 1 : 0;
    }

    public int findBestValue(int[] nums, int target) {
        int low = 0;
        int high = 0;

        for(int x : nums) high = Math.max(high, x);

        int ans = high;

        while(low <= high){
            int mid = (low + high) / 2;

            if(check(nums, mid, target) == 1){
                ans = mid;
                high = mid - 1;   // first valid
            } else {
                low = mid + 1;
            }
        }

        // check ans and ans-1 (closest logic)
        int sum1 = 0, sum2 = 0;

        for(int x : nums){
            sum1 += (x > ans ? ans : x);
            sum2 += (x > ans-1 ? ans-1 : x);
        }

        if(Math.abs(sum2 - target) <= Math.abs(sum1 - target)) return ans - 1;
        return ans;
    }
}