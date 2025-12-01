class Solution {
public:

    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]= find(parent[x]);
    }

    void Union(int a, int b){
        int u= find(a); int v= find(b);

        if(u==v)return;

        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
        
    }
    
    vector<int> processQueries(int n, vector<vector<int>>& con, vector<vector<int>>& queries) {
        parent.assign(n+1,0);
        rank.assign(n+1,0);

        for(int i=1; i<=n; i++){
            parent[i]=i;
        }

        for(int i=0; i<con.size(); i++){
            Union(con[i][0],con[i][1]);
        }

        vector<priority_queue<int,vector<int>,greater<int>>>pq(n+1);

        for(int i=1; i<=n; i++){
            pq[find(i)].push(i);
        }

        vector<int>on(n+1,1);
        vector<int>ans;

        for(auto&q:queries){
            int t= q[0], x= q[1], r=find(x);

            if(t==1){
                if(on[x]){
                    ans.push_back(x);
                }
                else{
                    auto &p= pq[r];
                    while(!p.empty() && !on[p.top()])
                        p.pop();
                    ans.push_back(p.empty() ? -1 : p.top());
                }
            }
            else{// when t==2;
                if(on[x]){
                    on[x]=0;
                }
            }
        }

        return ans;   
    }
};