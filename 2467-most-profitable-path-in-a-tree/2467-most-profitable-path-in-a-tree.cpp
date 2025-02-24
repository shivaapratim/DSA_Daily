class Solution {
public:

    int maxi;
    unordered_map<int,int>mp; //Bob's value store

    bool solveBob(int time, int bob, vector<vector<int>>&adj, vector<bool>&vis){
        vis[bob]=true;
        mp[bob]=time;

        if(bob==0)return true;

        for(auto&v: adj[bob]){
            if(!vis[v]){
                if(solveBob(time+1,v,adj,vis)){//Means bob got root.
                    return true;
                }
            }
        }
        mp.erase(bob);//Backtrack and try another node
        return false; 
    }


    void solveAlice(int node, int time , int curr, vector<bool>&vis, vector<vector<int>>&adj, vector<int>&amount){
        vis[node]=true;

        if(mp.find(node)==mp.end() || time<mp[node]){ //The other condition means alice reached before bob's time
            curr+=amount[node];
        }
        else if(time==mp[node]){
            curr+=amount[node]/2;
        }
        //How will u know that it is a leaf node??
        //In the adj list there will be only one item connected to it.

        if(adj[node].size()==1){
            maxi=max(maxi,curr);
        }

        for(int&v:adj[node]){
            if(!vis[v]){
                solveAlice(v,time+1,curr,vis,adj,amount);
            }
        }
    }




    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        //So what im thinking for this problem is
        //We have to maximize alice's score without even concerning about bob's
        //Actually we are only concerned about bob is that is it gets on same node of alice
        //Meaning i==j at some point then alice will get half the value from that node
        //Also bob is benifitial to make array elements as 0 means we have visited that place
        //Same applies to alice...SO SUMMING UP->

        //Alice-> Calculate and maximize a sum maybe recursion + val of that node
        //     -> If i==j occurs then give half to alice
        //     -> Make elements 0 so no one again takes it.
        
        //Bob  -> If i==j occurs then give half to alice
        //     -> Make elements 0 so no one again takes it.

        //I think it is somewhat like a Multisource bfs question where alice and bob work simultaneously

        int n=amount.size();
        vector<vector<int>>adj(n);
      

         maxi=INT_MIN;

        for(auto it: edges){
            int a=it[0];
            int b=it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int time=0;
        vector<bool>vis(n,false);
        solveBob(time,bob,adj,vis);    
        fill(vis.begin(),vis.end(),false);

        int curr=0; //Current alice income will be computed with maxi
        solveAlice(0,0,curr,vis,adj,amount);  // node,time,currentincome 

        return maxi;
    }
};