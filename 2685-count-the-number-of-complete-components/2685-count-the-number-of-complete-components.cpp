class Solution {
public:

    //Components jinme cycles hon toh ans++;
    //Cycle means edge= v*(v-1)/2 

    void dfs(int u, vector<int>&vis, vector<vector<int>>&adj, int&edg, int&ver){
        vis[u]= 1;
        ver++;
        for(auto&v: adj[u]){
            edg++;
            if(!vis[v]){
                dfs(v,vis,adj,edg,ver);
            }
        }

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<int>vis(n,0);
        int ans=0;

         vector<vector<int>> adj(n);
 
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i=0; i<n; i++){
            
            if(!vis[i]){
                int edg=0,ver=0;
                dfs(i,vis,adj,edg,ver);
                if(edg/2==(ver*(ver-1))/2){
                    ans++;
                }
            }

        }
        return ans;        
    }
};