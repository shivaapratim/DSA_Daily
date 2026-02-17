class Solution {
    public int search(int[] nums, int target) {
        int low=0;
        int high=nums.length-1;
        int ans=0;

        while(low<=high){
            int mid= (low+high)/2;
            if(nums[mid]<target){
                low= mid+1;
            }
            else if(nums[mid]==target || nums[mid]>target){
                ans=mid;
                high=mid-1;
            }
        }

        return nums[ans]==target ? ans : -1;

    }
}