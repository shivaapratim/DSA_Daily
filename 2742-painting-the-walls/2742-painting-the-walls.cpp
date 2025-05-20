class Solution {
public:
    int dp[501][501];

    int solve(int i,vector<int>&cost, vector<int>&time, int n, int walls){
        if(walls<=0)return 0;
        if(i>=n){  
            return INT_MAX;
        }

        if(dp[i][walls]!=-1)return dp[i][walls]; 

        int pick=INT_MAX; int notpick=0;
        int temp = solve(i+1, cost, time, n, walls - 1 - time[i]); // 1->{Painter 1} in the mean time->P2
        if(temp != INT_MAX) {
            pick = temp + cost[i];
        }
        
        notpick= solve(i+1,cost,time,n,walls);
 
        return  dp[i][walls] = min(pick,notpick);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,cost,time,n,n);
    }
};