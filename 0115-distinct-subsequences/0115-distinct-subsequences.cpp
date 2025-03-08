class Solution {
public:
    int dp[1001][1001];

    int solve(int i, int j, string&s, string&t){
        if(j==t.length())return 1;
        if(i>=s.length()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        //result variable += is better 
        
        int take=0;int nottake=0;
        nottake=solve(i+1,j,s,t);
        if(s[i]==t[j]){
            take= solve(i+1,j+1,s,t);
        }
       
        return dp[i][j] = take+nottake;

    }

    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};