class Solution {
public:
    // int minTaps(int n, vector<int>& ranges) {
    //     int taps=0;
    //     vector<int>startEnd(n+1,0);

    //     // main problem is to where will the taps be opened for the best case.

    //     // For this we have taken another variable curr, which will tell from a specific
    //     //Index it where we can go and when it exhausts we open the tap


    //     int s=0;int e=0;
    //     for(int i=0; i<ranges.size();i++){
    //         //Precompute the length of left and right side.
    //         s=max(i-ranges[i],0);
    //         e=min(i+ranges[i],n);

    //         startEnd[s]= max(startEnd[s],e);
    //     }

    //     int maxEnd=0;
    //     int curr=0;

    //     for(int i=0; i<ranges.size(); i++){
            
    //         if(i>maxEnd){
    //             return -1;
    //         }
    //         if(i>curr){
    //             taps++;
    //             curr=maxEnd;
    //         }
    //         maxEnd= max(maxEnd,startEnd[i]);

    //     }

    //     return taps;
    // }
    
    vector<vector<int>>dp;


    int solve(int n,int i, vector<pair<int,int>>&s, int maxEnd){
        
        if(i>=s.size()){
            return maxEnd >= n ? 0 : 1e9;
        }
        
        // if(i>=ranges.size()){
        //     if(maxEnd>=n)return 0;// Means we dont want to open any other tap.
        //     else return 1e9;// Means we didn't reach a specific case so infinite taps open
        // }

        //Basic knapsack...open notopen
        
        if(s[i].first>maxEnd){
            return 1e9; 
        }

        if(dp[i][maxEnd]!=-1){
            return dp[i][maxEnd];
        }

        int notopen=solve(n,i+1,s,maxEnd);
        int open= 1+solve(n,i+1,s,max(maxEnd,s[i].second));
        return dp[i][maxEnd] = min(open,notopen);
    }

    int minTaps(int n, vector<int>& ranges) {
        
        vector<pair<int,int>>s;
        dp = vector<vector<int>>(ranges.size(), vector<int>(n + 1, -1));
        for(int i=0; i<ranges.size(); i++){
            int l = max(i-ranges[i],0);
            int r = min(ranges[i]+i,n);
            s.push_back({l,r});
        }
        sort(s.begin(),s.end());
        int res= solve(n,0,s,0);

        return res == 1e9 ? -1 : res;
    }
};