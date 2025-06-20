class Solution {
public:

    int dp[1001][1001];

    int findNext(const vector<vector<int>>& events, int current_end, int low) {
        int high = events.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > current_end)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    int solve(int level, vector<vector<int>>&events, int k){
        if(level>=events.size() || k==0){
            return 0;
        }

        if(dp[level][k]!=-1)return dp[level][k];

        int pick=0; 

        int notpick= solve(level+1,events,k);

        int next_event_index = findNext(events, events[level][1], level + 1);
        
        pick = events[level][2] + solve(next_event_index, events, k-1);
        

        return dp[level][k] = max(pick,notpick);

    }

    int maxValue(vector<vector<int>>& events, int k) {
        
        sort(events.begin(),events.end());

        memset(dp,-1,sizeof(dp));

        return solve(0,events,k);

    }
};