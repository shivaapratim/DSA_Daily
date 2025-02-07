class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=edges.size();
        int N=colors.size();
        vector<vector<int>>adj(N);
        vector<int>indegree(N,0);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            indegree[v]++;
        }   

        queue<int>q;

        vector<vector<int>>t(N,vector<int>(26,0));

        for(int i=0; i<N;i++){
            if(indegree[i]==0){
                q.push(i);
                t[i][colors[i]-'a']=1;
            }
        }

        int ans=0;
        int cntnode=0;//For cycle check

        while(!q.empty()){
            int u= q.front();
            q.pop();
            cntnode++;
            ans= max(ans,t[u][colors[u]-'a']);

            for(int&v:adj[u]){
                for(int i=0; i<26; i++){
                    t[v][i]= max(t[v][i], t[u][i]+(colors[v]-'a'==i)); //Prev--->> + new??
                }
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(cntnode<N)return -1;// cycle

        return ans;

    }
};