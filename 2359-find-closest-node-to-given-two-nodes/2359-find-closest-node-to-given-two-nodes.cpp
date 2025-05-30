class Solution {
public:

    void dfs(int u, vector<pair<int,int>>&arr, vector<int>&edges, vector<int>&vis, int val){
        vis[u]=1;
        arr[u]={val,u};

        if(edges[u]==-1)return;

        if(!vis[edges[u]])
        dfs(edges[u],arr,edges,vis,val+1);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n= edges.size();

        vector<pair<int,int>>None(n,{-1,-1}); 
        vector<pair<int,int>>Ntwo(n,{-1,-1});
        vector<int>vis(n,0);

        dfs(node1,None,edges,vis,0);

        fill(vis.begin(),vis.end(),0);

        dfs(node2,Ntwo,edges,vis,0);

        int mini=INT_MAX;
        int idx=-1;
        for(int i=0; i<n; i++){
            if(None[i].first==-1 || Ntwo[i].first==-1)continue;
            cout<<mini;
            if( mini > max(None[i].first,Ntwo[i].first) ){
                mini= max(None[i].first,Ntwo[i].first);
                idx = i;
            }
        }

        return idx;
    }
};