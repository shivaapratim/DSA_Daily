class Solution {
public:
    int Q[10];// at what col is my queen at row i.

    bool check(int row, int col){
        for(int i=0; i<row; i++){
            int prow = i;
            int pcol = Q[i];

            if(pcol==col || (abs(pcol-col)==abs(row-prow))){
                return false;
            }
        }

        return true;
    }

    int solve(int level, int n){
        if(level==n)return 1;

        int ans=0;

        for(int col=0; col<n; col++){
            if(check(level,col)){
                Q[level]=col;
                ans+=solve(level+1,n);
                Q[level]=-1;
            }
        }
        return ans;
    }

    int totalNQueens(int n) {
        memset(Q,-1,sizeof(Q));
        return solve(0,n);
    }
};