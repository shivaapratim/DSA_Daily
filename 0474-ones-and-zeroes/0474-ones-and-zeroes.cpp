class Solution {
public:
    
    int dp[605][105][105];

    void pairing(vector<string>&strs, vector<vector<int>>&arr){

        for(string it: strs){
            int ones=0;
            int zeros=0;

            for(char i: it){  
                if(i == '1'){
                    ones++;
                    
                }
                else if(i == '0'){
                    zeros++;
                }

            }

            arr.push_back({zeros,ones});
        }

    }

    int solve(int i, vector<vector<int>>&arr, int m, int n){
        //base case
        if(i>=arr.size() || (m<=0 && n<=0) ){
            return 0;
        }
        //cache
 
        if(dp[i][m][n]!=-1)return dp[i][m][n];   

        //choice
        int take=0;
        int nottake= solve(i+1, arr, m, n);


        //check
        if(m-arr[i][0]>=0 && n-arr[i][1]>=0  ){
            take= 1 + solve(i+1, arr, m-arr[i][0], n-arr[i][1]);
        }

        return dp[i][m][n] = max(take,nottake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>arr;    

        pairing(strs,arr);
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,arr,m,n);

    }
};