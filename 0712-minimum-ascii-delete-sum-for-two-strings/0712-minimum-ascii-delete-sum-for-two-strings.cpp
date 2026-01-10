class Solution {
public:

    int dp[1001][1001];

    int rem(int i, string x){
        int sum=0;

        for(;i<x.length();i++){
            sum+=x[i];
        }

        return sum;
    }

    int solve(int i, int j, string&s, string&t){
        //Level

        if(i>=s.length()){
            return rem(j,t);
        }
        if(j>=t.length()){
            return rem(i,s);
        }

        
        if(dp[i][j]!=-1)return dp[i][j]; 
        
        //choice
        int pick1=INT_MAX;
        int pick2=INT_MAX;
        int pick3=INT_MAX;
        int ans=INT_MAX;

        //check
        if(s[i]==t[j])
        pick1 = solve(i+1,j+1,s,t);

        pick2= s[i] + solve(i+1,j,s,t);
        pick3= t[j] + solve(i,j+1,s,t);

        //move
        return dp[i][j] = ans=min({pick1,pick2,pick3}); 
    }

    int minimumDeleteSum(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};