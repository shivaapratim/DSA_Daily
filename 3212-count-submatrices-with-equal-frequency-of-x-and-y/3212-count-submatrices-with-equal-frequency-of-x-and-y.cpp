class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

       
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;

        vector<vector<pair<int,int>>>p(n,vector<pair<int,int>>(m,{0,0}));


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(i-1>=0){
                    p[i][j].first += p[i-1][j].first;
                    p[i][j].second += p[i-1][j].second;
                }
                if(j-1>=0){
                    p[i][j].first += p[i][j-1].first;
                    p[i][j].second += p[i][j-1].second;
                }
                if(i-1>=0 && j-1>=0){
                    p[i][j].first -= p[i-1][j-1].first;
                    p[i][j].second -= p[i-1][j-1].second;
                }

                if(grid[i][j]=='X'){
                    p[i][j].first++;
                }

                if(grid[i][j]=='Y'){
                    p[i][j].second++;
                }

                // Checking validity

                if(p[i][j].first==p[i][j].second && p[i][j].first>0){
                    ans++;
                }

            }
        }

        return ans;

    }
};