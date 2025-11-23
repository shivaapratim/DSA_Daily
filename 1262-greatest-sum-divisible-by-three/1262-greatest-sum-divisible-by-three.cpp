class Solution {
public:

    int dp[100001][3];
    vector<int>arr;
    int solve(int i, int rem) {
        if (i == arr.size()) 
            return (rem == 0 ? 0 : INT_MIN);

        if (dp[i][rem] != -1) return dp[i][rem];

        int take = arr[i] + solve(i + 1, (rem + arr[i]) % 3);
        int not_take = solve(i + 1, rem);

        return dp[i][rem] = max(take, not_take);
    }

    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        
        int maxSum=0;

        for(auto i: nums){
            if(i%3==0){
                maxSum+=i;
            }
            else{
                arr.push_back(i);
            }
        }

        int giveMax = solve(0,0);
        return giveMax+maxSum;
    }
};