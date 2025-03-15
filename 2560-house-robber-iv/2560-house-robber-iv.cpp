class Solution {
public:

    // vector<vector<int>>dp;

    // int solve(vector<int>&nums, int i, int k,vector<int>&arr){
    //     if (i >= nums.size()) {
    //     // If k > 0 here, this is an invalid branch.
    //     if (k > 0) return INT_MAX;
    //     // If just finishing selection, ensure arr is not empty.
    //         return arr.empty() ? 0 : *max_element(arr.begin(), arr.end());
    //     }
    //     if (k == 0) {
    //        return arr.empty() ? 0 : *max_element(arr.begin(), arr.end());
    //     }

    //     if(dp[i][k]!=-1)return dp[i][k];
       
    //     arr.push_back(nums[i]);
    //     int pick = solve(nums,i+2,k-1,arr);
    //     arr.pop_back();
    //     int notpick= solve(nums,i+1,k,arr);

    //     return dp[i][k]= min(pick,notpick);
    // }

    // int minCapability(vector<int>& nums, int k) {
    // //     dp.resize(nums.size(),vector<int>(k+1,-1));
    // //     vector<int>arr;
    // //     return solve(nums,0,k,arr);


    // }     
   

 
    // Helper function that checks if we can pick k non-adjacent numbers <= cap.
    bool canPick(vector<int>& nums, int k, int cap) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= cap) {
                count++;
                i++; // Skip the next index to maintain non-adjacency.
            }
            if (count >= k) return true;
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canPick(nums, k, mid)) {
                right = mid;  // Candidate is good; try to lower it.
            } else {
                left = mid + 1;
            }
        }
        return left;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
};