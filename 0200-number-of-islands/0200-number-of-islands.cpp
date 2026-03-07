class Solution {
public:

void bfs(vector<vector<char>>& grid,int i,int j){
    
    queue<pair<int,int>>q;
    q.push({i,j}); 
    int row=grid.size();
    int col=grid[0].size();
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int k=0;k<4;k++)
        {
        int newrow=r+delrow[k];
        int newcol=c+delcol[k];

        if(newrow>=0 && newrow<row && newcol>=0 && newcol<col && grid[newrow][newcol]=='1')
        {
            grid[newrow][newcol]=0;
            q.push({newrow,newcol});
        }
        }
        
    }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

   
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;

    }
};