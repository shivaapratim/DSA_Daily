class Solution {
public:
    
    typedef long long ll;

    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<ll,ll> mp;
        vector<ll> dp(n+1, 0);
        dp[0] = 0;

        mp[0LL] = 0LL;

        ll sumRem = 0;

        for (int i = 1; i <= n; i++) {
            sumRem = (sumRem + nums[i-1]) % k;

            dp[i] = dp[i-1] + nums[i-1];

            auto it = mp.find(sumRem);
            if (it != mp.end()) {
                dp[i] = min(dp[i], it->second);
            }// independent

            if (it == mp.end()) {
                mp[sumRem] = dp[i];
            } 
            
            else if (dp[i] < it->second) {
                it->second = dp[i];
            }
        }

        

        return dp[n];
    }
};
