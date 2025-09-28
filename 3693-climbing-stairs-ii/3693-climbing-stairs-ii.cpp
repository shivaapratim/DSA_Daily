class Solution {
public:
    int dp[10005];

    int solve(int i, vector<int>& costs) {
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];

        int res = INT_MAX;

        // jump of 1
        if (i - 1 >= 0)
            res = min(res, solve(i - 1, costs) + costs[i - 1] + 1);

        // jump of 2
        if (i - 2 >= 0)
            res = min(res, solve(i - 2, costs) + costs[i - 1] + 4);

        // jump of 3
        if (i - 3 >= 0)
            res = min(res, solve(i - 3, costs) + costs[i - 1] + 9);

        return dp[i] = res;
    }

    int climbStairs(int n, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(n, costs);
    }
};
