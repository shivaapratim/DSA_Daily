class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        // set<int>key;
        // set<int>resolve;
        vector<int>key(status.size(),0);
        vector<int>resolve(status.size(),0);

        queue<int>q;

        for(int i: initialBoxes){
            q.push(i);
        }
       

        int ans=0;

        while(!q.empty()){
            int n= q.size();
            vector<int>temp;
            bool progress=false;
            while(n--){// Process a level 
                int u= q.front();
                q.pop();
                if(resolve[u]==1)continue;

                if(status[u]==1 || key[u]==1){
                    progress=true;
                    ans+=candies[u];
                    for(int i: keys[u])key[i]=1;
                    for(int i: containedBoxes[u])temp.push_back(i);
                    resolve[u]=1;
                }
                else{
                    temp.push_back(u);
                }
            }
            if (!progress) break;
            for(int i: temp){// Insert nodes of second level
                q.push(i);
            }
        }
        return ans;
    }
};