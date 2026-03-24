class Solution {
public:

    int MOD=12345;
    int n;
    int m;
    typedef long long ll;

    void flatten(vector<vector<int>>&grid, vector<int>&arr){
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                arr.push_back(grid[i][j]); 
            }
        }
    }

    vector<int> findProduct(vector<int>&arr){
        int n=arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);

        for(int i=0; i<n; i++){
            if(i==0){
                left[i]=1;
            }
            else left[i]=((ll)left[i-1]*arr[i-1])%MOD;
        }

        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                right[i]=1;
            }
            else right[i]=((ll)right[i+1]*arr[i+1])%MOD;
        }

        vector<int>ans(n,0);

        for(int i=0; i<n; i++){
            ans[i]= ((ll)left[i]*right[i])%MOD;
        }

        return ans;
    }

    void makeGrid(vector<int>&ans, vector<vector<int>>&grid){
        int k = 0;

        for(int i = 0; i < n; i++){
            vector<int> row;
            for(int j = 0; j < m; j++){
                row.push_back(ans[k++]);
            }
            grid.push_back(row);
        }
    }

    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<int>arr;
        n=grid.size();
        m=grid[0].size();

        flatten(grid,arr);

        vector<int>ans=findProduct(arr);

        vector<vector<int>>newGrid;
        makeGrid(ans,newGrid);

        for(int i=0; i<ans.size();i++){
            cout<<ans[i]<<" ";
        }

        return newGrid;
    }
};