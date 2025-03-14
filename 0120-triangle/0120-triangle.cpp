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


        int levels = triangle.size();
        if (levels == 0) return 0;

        // Flatten the triangle into a 1D array.
        vector<int> nums;
        for (int i = 0; i < levels; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                nums.push_back(triangle[i][j]);
            }
        }
        
        // Total number of elements in the flattened array.
        int totalElements = nums.size();
        // Create a DP vector of the same size as nums.
        // dp[i] will store the minimum path sum starting from the element at flattened index i.
        vector<int> dp(totalElements, 0);
        
        // Initialize the DP for the bottom row.
        // In a triangle with 'levels' rows, the bottom row has indices starting from:
        // startBottom = levels*(levels-1)/2 and has 'levels' elements.
        int startBottom = levels * (levels - 1) / 2;
        for (int j = 0; j < levels; ++j) {
            dp[startBottom + j] = nums[startBottom + j];
        }
        
        // Process the triangle from the second last row up to the top.
        for (int r = levels - 2; r >= 0; --r) {
            // The starting index for row r in the flattened structure.
            int startIndex = r * (r + 1) / 2;
            for (int c = 0; c < r + 1; ++c) {
                int index = startIndex + c; // flattened index for cell (r, c)
                // Calculate children indices in the flattened array.
                int leftChild  = (r + 1) * (r + 2) / 2 + c;
                int rightChild = leftChild + 1;
                // The DP recurrence: current cell's value plus the minimum of its two children.
                dp[index] = nums[index] + min(dp[leftChild], dp[rightChild]);
            }
        }
        
        // dp[0] now contains the minimum path sum from the top of the triangle.
        return dp[0];

    }
};