class Solution {
    public boolean isMonotonic(int[] nums) {
        int inc = 1, dec = 1;
        
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] > nums[i-1]) dec = 0;
            if(nums[i] < nums[i-1]) inc = 0;
        }
        
        return inc == 1 || dec == 1;
    }
}