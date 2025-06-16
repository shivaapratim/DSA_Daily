class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int i){
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i]);
    }

    void Union(int x, int y){
        int x_p= find(x);
        int y_p= find(y);

        if(x_p==y_p){
            return ;
        }
        if(rank[x_p]<rank[y_p]){
            parent[x_p]=y_p;
        }
        else if(rank[x_p]>rank[y_p]){
            parent[y_p]=x_p;
        }
        else{
            parent[x_p]=y_p;
            rank[y_p]++;
        }
    }


    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n,0);
        rank.resize(n);

        for(int i=0; i<n; i++){
            parent[i]=i;
        }

        for(int i=0; i<queries.size();i++){
            queries[i].push_back(i);
        }

        auto lambda = [&](vector<int>&v1, vector<int>&v2){
            return v1[2]<v2[2];
        }; 

        sort(edgeList.begin(),edgeList.end(),lambda);
        sort(queries.begin(),queries.end(),lambda);
        
        int j=0;

        vector<bool>result(queries.size(),false);


        for(auto q: queries){
            int u = q[0];
            int v = q[1];
            int w = q[2];
            int idx = q[3];

            while(j<edgeList.size() && edgeList[j][2]<w){
                Union(edgeList[j][0],edgeList[j][1]);
                j++;
            }

            result[idx]= find(u) == find(v);    

        }

        return result;

    }
};