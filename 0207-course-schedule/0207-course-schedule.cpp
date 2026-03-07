class Solution {
public:

//     // The significance of count is to check if cycle exists or not
      
//       // 0->1->2   Indegree-> 0-1 1-2 2-1 3-1
//       //    ^  |
//       //    |  |
//       //    3<-
//       //  In this when we will push q it will explore for 0 and see 1, but 1's indegree will
//       //  become 2-1=1 and this won't be pushed and we can't explore further so it is a cycle.
//     // bool canFinish(int n, vector<vector<int>>& pre) {
//     //     vector<int>indegree(n,0);
//     //     vector<vector<int>>adj(n);
//     //     queue<int>q;

//     //     for(auto &v: pre){
//     //         int a= v[0];
//     //         int b= v[1];
            
//     //         adj[b].push_back(a);
//     //         indegree[a]++;
//     //     } 
//     //     int count=0;

//     //     for(int i=0; i<n; i++){
//     //         if(indegree[i]==0){
                 
//     //             q.push(i);
//     //         }
//     //     }
       
//     //     while(!q.empty()){
//     //         int u= q.front();
//     //         count++;
//     //         q.pop();
            
//     //         for(int &i: adj[u]){
                
//     //                 indegree[i]--;
//     //                 if(indegree[i]==0){
 
//     //                     q.push(i);
//     //                 }
                 
//     //         }
//     //     }
//     //    return count==n;
//     // }



//     // DFS

//     bool cycle(vector<int>&vis,vector<vector<int>>&adj, int u, vector<int>&inRec){
//         vis[u]=1;
//         inRec[u]=1;
//         for(int &v: adj[u]){
//             if(!vis[v] && cycle(vis,adj,v,inRec)){
//                 return true;
//             }
//             else if(inRec[v]==1){
//                 return true;
//             }
//         }
//         inRec[u]=0;
//         return false;
//     }

//     bool canFinish(int n, vector<vector<int>>& pre){
//         vector<vector<int>>adj(n);
//         for(auto &it: pre){
//             int a=it[0];
//             int b=it[1];
//             //Directed
//             adj[b].push_back(a);
//         }

//         vector<int>vis(n,0);
//         vector<int>inRec(n,0);
//         for(int i=0; i<n; i++){
//             if(!vis[i] && cycle(vis,adj,i,inRec)){
//                 return false;
//             }
//         }
//         return true;
        
//     }
    
// };

bool canFinish(int n, vector<vector<int>>& pre){
    vector<vector<int>>adj(n);

    vector<int>indegree(n,0);

    for(auto it: pre){
        int u= it[1];
        int v= it[0];
        
        adj[u].push_back(v);
        indegree[v]++;
    }

    int cnt=0;

    queue<int>q;

    for(int i=0; i<n; i++){
        if(indegree[i]==0)q.push(i);
    }

    while(!q.empty()){
        int u= q.front();
        q.pop();

        cnt++;

        for(auto v: adj[u]){
            indegree[v]--;
            if(indegree[v]==0)q.push(v);
        }
    }

    return cnt==n;

}

};


