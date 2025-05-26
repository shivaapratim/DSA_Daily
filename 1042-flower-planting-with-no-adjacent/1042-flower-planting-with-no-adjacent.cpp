    class Solution {
    public:

        void check(int v, vector<int>&color, vector<vector<int>>&adj){
            
            for(int i=1; i<=4; i++){
                int filled=0;
                for(auto c: adj[v]){
                    if(color[c]==i){
                        filled=1;
                        break;
                    }
                }
                if(filled==0){
                    color[v]=i;
                    return;
                }
            }

        }

        void dfs(int u, vector<vector<int>>&adj, vector<int>&color, vector<int>&vis){
            vis[u]=1;
            check(u,color,adj);

            for(auto v: adj[u]){
                if(!vis[v]){
                    dfs(v,adj,color,vis);
                }
            }

        }

        vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
            vector<vector<int>>adj(n+1);

            if(n==1)return {1};

            for(auto it: paths){
                int u= it[0];
                int v= it[1];

                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            vector<int>color(n+1,0);
            vector<int>vis(n+1,0);

            for(int i=1; i<=n; i++){
                if(!vis[i]){
                    dfs(i, adj, color, vis);
                }
            }

            color.erase(color.begin());

            return color;

        }
    };