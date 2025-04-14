class Solution {
public:


    void dfs(int u,vector<int>&vis,set<pair<int,int>>&st, vector<vector<int>>&adj, vector<int>&quiet){
        vis[u]=1;
        st.insert({quiet[u],u});
        for(auto v: adj[u]){
            if(!vis[v]){
                dfs(v,vis,st,adj,quiet);
            }
        }
    }


    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n= quiet.size();
        vector<vector<int>>adj(n);

        for(auto it: richer){
            int u= it[0];
            int v= it[1];

            adj[v].push_back(u); // 0 -> 1
        }

        vector<int>ans(n);

        for(int i=0; i<n; i++){
            vector<int>vis(n,0);
            
            set<pair<int,int>>st; // first is value, second is element(person)
            // Add the current person to the set and explore all richer people
            st.insert({quiet[i], i});
            
            dfs(i,vis,st,adj,quiet);
            ans[i] = st.begin()->second;
        }
        return ans;
    }
};