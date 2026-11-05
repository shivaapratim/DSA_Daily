class Solution {
    
    int dp[] = new int[101];

    public int solve(int level, int n){
        if(level==n)return 1;

        if(dp[level]!=-1)return dp[level];

        int ans=0;
        for(int steps=1; steps<=2; steps++){
            if(level+steps<=n){
                int ways = solve(level+steps,n);
                ans+=ways;
            }
        }
        return dp[level] = ans;
    }

    public int climbStairs(int n) {
        Arrays.fill(dp,-1);
        return solve(0,n);
    }
}