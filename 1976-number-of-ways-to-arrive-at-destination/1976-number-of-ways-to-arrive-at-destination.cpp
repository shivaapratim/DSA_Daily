class Solution {
public:

    //What if we first calculate the shortest time by using Dijkastra and then using DP
    //We can tell how many ways there are!
    //Also the only thing we need to keep in mind is that this is a graph not a tree 
    //So while doing recursion we will have to take care about the visited nodes in order
    //To be sure which elements are already visited and we dont get stuck in any loop.

    const int MOD= 1e9+7;
    const long long INF = 1e18;  // simple constant for "infinity"

    int solve(int i,unordered_map<int,vector<pair<int,int>>>&adj, vector<long long>&ans,vector<int>&dp, int dest){
        if(i==dest){
            return 1;
        }
        if(dp[i]!=-1)return dp[i];

        long long pick=0;
        for(auto&it: adj[i]){
            int adjnode = it.first;
            int wt = it.second;
            if(ans[i]+wt==ans[adjnode]){
                pick = (pick + solve(adjnode,adj,ans,dp,dest))%MOD;
            }
        }
        return dp[i]=pick;
        

    }



    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto it: roads){
            int u= it[0];
            int v= it[1];
            int wt= it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

        
        vector<long long>ans(n,INF);

        ans[0]=0;//src
        pq.push({0,0});

        while(!pq.empty()){
            long long d=pq.top().first;
            int u=pq.top().second;
            pq.pop();

            if(d>ans[u])continue;//Skip outdated entry

            for(auto&v: adj[u]){
                int adjnode= v.first;
                int wt= v.second;

                if(d+wt<ans[adjnode]){
                    ans[adjnode]=d+wt;
                    pq.push({d+wt,adjnode});
                }
            }
        }

        int shortest= ans[n-1];

        //Check
        if(shortest==INF)return 0;

        //Now DP
        //Inrecursion visited array is important so visited array will be variable for
        //Each call of recursion
        vector<int>dp(n,-1);
        return solve(0,adj,ans,dp,n-1);

    }
};