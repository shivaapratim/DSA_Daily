class Solution {
public:
    /*
    Well if we assume this as 1D and to formulate the places we can go according to levels
    it might be easy for us to understand.

    Well let us assume rows as levels starting from 0, and a index 'i' for the whole 1D matrix

    Now the math behind this is ki at every level the row size increases by 1.

    So same means the condtions, means if we are at level 0 then we can go for level+i+1
    or to level+i+2 -> [2, 3,4  6,5,7], and same applies for further, also everytime we just
    have to increase the level by 1 cause it is the only value by which at every row an element
    increases. 

    Also if we try to observe then this somehow looks like a recursive process cause, we have options

    either we can go to level+i+1 or level+i+2;

    Boiling down this concept to simple jump game equation where we just have to reach to n,
    just the twist is we have to reach to the last level

    This means to triangle.size()

    So here we got our base case-> if(triangle.size()==level) then we return. 

    In the mean time our recursion will explore all the possible paths and formulate the min value.

    Just a thing in mind that if there are levels and we have to find minimum path then bfs is a much
    better approach.

    Approach
    -> First just make the array into single one. 
    -> Then apply the logic and pick1 pick2 thing and find the min.
    */ 

    // int solve(int i, int level, vector<int>&nums,vector<vector<int>>&triangle){
        
    //     if(level==triangle.size()){
    //         return 0;
    //     }

    //     // if(i+level+1<=nums.size()){
    //     int pick1=solve(level+i+1,level+1,nums,triangle)+nums[i];
    //     // }
    //     // if(i+level+2<=nums.size()){
    //     int pick2=solve(level+i+2,level+1,nums,triangle)+nums[i];
    //     // }

    //     return min(pick1,pick2);

    // }

    int minimumTotal(vector<vector<int>>& triangle) {
    
        // vector<int>nums;

        // for(int i=0; i<triangle.size();i++){
        //     for(int j=0; j<triangle[i].size();j++){
        //         nums.push_back(triangle[i][j]);
        //     }
        // }
        // return solve(0,0,nums,triangle);

        //bfs

        // int n=triangle.size();
        // if(n==0)return 0;

        // queue<pair<int,int>>q;

        // q.push({0,triangle[0][0]});

        // int level=0;// will work as i, row

        // while(level<n-1){
        //     int size=q.size();

        //     for(int k=0; k<size; k++){
        //         int col= q.front().first;
        //         int currsum= q.front().second;
        //         q.pop();

        //         q.push({col,currsum+triangle[level+1][col]});
        //         q.push({col+1,currsum+triangle[level+1][col+1]});
        //     }
        //     level++;
        // }

        // int ans=INT_MAX;
        // while(!q.empty()){
        //     ans=min(ans,q.front().second);
        //     q.pop();
        // }
        // return ans;


        //The best and working-> tabulation

        int n= triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int j=n-1; j>=0; j--) {
            dp[n-1][j]=triangle[n-1][j];
        }

        for(int i= n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int down= triangle[i][j] + dp[i+1][j];
                int downright= triangle[i][j] + dp[i+1][j+1];

                dp[i][j]=min(down, downright);
            }
        }
        return dp[0][0];
    }
};