class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m= mat[0].size();
        int n= mat.size();

        k=k%m;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                int curridx=j;
                int finalidx;

                if(i%2==0){
                    finalidx= (j+k)%m; 
                }
                else{
                    finalidx= (j-k+m)%m;
                }

                if(mat[i][curridx]!=mat[i][finalidx]){
                    return false;
                }
            }
        }
        return true;
    }
};