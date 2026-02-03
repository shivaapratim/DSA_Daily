class Solution {
    public int majorityElement(int[] nums) {
        int n=nums.length/2;

        Arrays.sort(nums);

        // 1 1 1 2 2 2 2 

        for(int i=0; i<nums.length; i++){
            int cnt=0;
            int j=i;
            while(j<nums.length && nums[i]==nums[j]){
                cnt++;
                j++;
            }
            if(cnt>n)return nums[i];
            i=j-1;
        }
        return -1;
    }
}