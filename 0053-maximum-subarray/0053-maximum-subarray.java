class Solution {
    public int maxSubArray(int[] nums) {
        int maximumSum = Integer.MIN_VALUE;
        int runningSum = 0;

        for(int i = 0; i < nums.length; i++){
            runningSum += nums[i];
            maximumSum = Math.max(maximumSum, runningSum);
            if(runningSum < 0) runningSum = 0;
        }

        return maximumSum;
    }
}