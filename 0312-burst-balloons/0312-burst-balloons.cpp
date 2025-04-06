class Solution {
public:

        //0 to n-1 , i assume that n is the number of balloons as the array size.
    //so here we can se the question stays with the logic of partition array
    //Which can also be solved using LR dp;.

    //Rod cutting problem..

    //points 

    //Counter intutive approach, what if we first burst a balloon and then go up
    // and then burst another balloon, means suppose we bursted 8 -> 1*8*1, then reverse
    //recursion and go to [3,8] since we know we have to burst 3 in this step, we can calculate
    // 1*3*8, go one step more upwards, we find [3,5,8], we can burst 5, calc= 3*5*8, this is how
    //reverse thing will work.

    //N this makes the solution counter intutive and independent solutions both ways.
    // (l,i-1) and (i+1,r)
    
    
    int dp[504][504];


    int solve(int l, int r, vector<int>&nums){
        if(l>r)return 0;

        if(dp[l][r]!=-1)return dp[l][r];

        int maxCoins=0;

        for(int i=l; i<=r; i++){
            int coins= nums[l-1] * nums[i] * nums[r+1];

            int left=solve(l,i-1,nums);
            int right=solve(i+1,r,nums);

            maxCoins=max(maxCoins,left+right+coins);
        }
        return dp[l][r] = maxCoins;
    }


    int maxCoins(vector<int>& nums) {
       
       int n=nums.size();
       memset(dp,-1,sizeof(dp));
       nums.insert(nums.begin(),1);
       nums.push_back(1);

       return solve(1,n,nums);

    }
};