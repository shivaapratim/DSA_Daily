class Solution {

    public int check(int[] nums, int mid, int k){
        int studentCnt=1;
        int sum=0;
        for(int i=0; i<nums.length; i++){
            if(sum+nums[i]>mid){
                studentCnt++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return studentCnt<=k ? 1 : 0;
    }

    public int splitArray(int[] nums, int k) {
        int low = Arrays.stream(nums).max().getAsInt();
;
        int high= Arrays.stream(nums).sum();
        int ans=low;
        
        while(low<=high){
            int mid= (low+high)/2;

            if(check(nums,mid,k)==1){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
}