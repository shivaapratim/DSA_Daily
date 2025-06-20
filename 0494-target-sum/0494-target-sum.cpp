class Solution {
public:
   

    int solve(int i, vector<int>&nums, int target, int ways, int sum){
        if(i>=nums.size()){
            if(sum==target){
                ways++;  
            }
            return ways;
        }

       

        int add=solve(i+1,nums,target,ways,sum+nums[i]);
        int sub=solve(i+1,nums,target,ways,sum-nums[i]);

        return add+sub;
    }
    
     

    int findTargetSumWays(vector<int>& nums, int target) {
     
        return solve(0,nums,target,0,0);
    }
};