class Solution {
public:
    int dp[13][10001];

    int solve(int i, vector<int>& coins, int t) {
        if (t == 0) return 0;
        if (i >= coins.size()) return INT_MAX;
        if (t < 0) return INT_MAX;

        if (dp[i][t] != -1)
            return dp[i][t];

        int take = INT_MAX;
        int res = solve(i, coins, t - coins[i]);

        if (res != INT_MAX)
            take = 1 + res;

        int notTake = solve(i + 1, coins, t);

        return dp[i][t] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));

        int ans = solve(0, coins, amount);

        return ans == INT_MAX ? -1 : ans;
    }
};