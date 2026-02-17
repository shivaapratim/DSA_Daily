class Solution {

    public int check(int mid, int []nums, int target){
        if(nums[mid]>=target)return 1;
        return 0;
    }

    public int search(int[] nums, int target) {
        int low= 0;// start index
        int high=nums.length-1; // last index
        int ans=0;

        while(low<=high){
            int mid= (low+high)/2;

            if(nums[mid]<target){
                low=mid+1;
            }
            else if(check(mid,nums,target)==1){
                ans=mid;
                high=mid-1;
            }
        }
            //nums[0]==0
        return nums[ans]==target ? ans : -1;
    }
}