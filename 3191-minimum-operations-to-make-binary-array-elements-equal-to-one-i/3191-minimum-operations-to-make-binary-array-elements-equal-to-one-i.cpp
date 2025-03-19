class Solution {
public:

    void flipped(int j,vector<int>&nums){
        for(int i=j; i<j+3; i++){
            if(nums[i]==1)nums[i]=0;
            else nums[i]=1;
        }
    }

    int minOperations(vector<int>& nums) {
        int n=nums.size();  
        int mini=0;

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                if(i==n-1 || i==n-2)return -1;
                flipped(i,nums);
                mini++;
            }
        }

        return mini;
    }
};