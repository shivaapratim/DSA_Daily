class Solution {
public:

    vector<vector<int>>dir= {{0,1},{1,0},{-1,0},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;

        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        int minute=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)fresh++;
            }
        }

        if(fresh==0)return 0;

        while(!q.empty()){
           
            int N=q.size();

            while(N--){
                int i= q.front().first;
                int j= q.front().second;
                q.pop();
                
                for(auto it: dir){
                    int i_=i+it[0];
                    int j_=j+it[1];

                    if(i_>=0 && j_>=0 && j_<m && i_<n && grid[i_][j_]==1){
                        grid[i_][j_]=2;
                        q.push({i_,j_});
                        fresh--;
                    }
                }
            }
            minute++;
        }
        return fresh==0 ? minute-1 : -1;
    }
};