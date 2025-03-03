class Solution {
public: 

    // unordered_map<string,vector<string>>adj;
    // vector<string>result;
    // int num=0;

    // bool dfs(string start,vector<string>&path){
    //     path.push_back(start);
    //     if(path.size()==num+1){
    //         result=path;
    //         return true;
    //     }
        
    //     vector<string>&neg=adj[start];

    //     for(int i=0; i<neg.size(); i++){
    //         string des=neg[i];

    //         neg.erase(neg.begin()+i);

    //         if(dfs(des,path)==true){
    //             return true;
    //         }
    //         neg.insert(neg.begin()+i,des);
    //     }
    //     path.pop_back();
    //     return false;
    // }


    // vector<string> findItinerary(vector<vector<string>>& tickets) {

    //     num=tickets.size();

    //     for(auto&it:tickets){
    //         string u=it[0];
    //         string v=it[1];

    //         adj[u].push_back(v);
    //     }

    //     //sorting function for lexicographical

    //     for(auto&it: adj){
    //         sort(it.second.begin(),it.second.end());
    //     }

    //     vector<string>path;
    //     dfs("JFK",path);
        
    //     return result;
        
    // void dfs(string u, unordered_map<string, int>&vis, unordered_map<string,vector<string>>&adj, vector<string>&arr){
    //     vis[u]=1;
    //     for(auto&v:adj[u]){
    //         if(!vis[v]){
    //             dfs(v,vis,adj,arr);
    //         }   q 
    //     }
    //     arr.push_back(u);
    // }


        // for(auto&it: tickets){
        //     string a=it[0];
        //     string b=it[1];

        //     adj[a].push_back(b);
        // }

        // for(auto&it:adj){
        //     sort(it.second.begin(),it.second.end());
        // }

        // vector<string>arr;
        // unordered_map<string, int> vis;

        // return arr;




 
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;
    void dfs(string u) {
        auto & edges = adj[u];
        
        while (!edges.empty())
        {
            string v = edges.top();
            edges.pop();
            dfs(v);
        }
        result.push_back(u);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto e : tickets)
            adj[e[0]].push(e[1]);
        
        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;

    }
};