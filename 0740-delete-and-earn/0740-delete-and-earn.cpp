class Solution {
public:
    vector<int> dp;
    
    int solve(int i, vector<int>& nums) {
        if (i >= nums.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        // Group current equal numbers starting at index i.
        int current = nums[i], groupSum = 0, j = i;
        while (j < nums.size() && nums[j] == current) {
            groupSum += current;
            j++;
        }
        
        // Option 1: Skip the current group.
        int skip = solve(j, nums);
        
        // Option 2: Take the current group.
        // If the next group (starting at index j) is a consecutive number,
        // skip over that entire group.
        int take = groupSum;
        if (j < nums.size() && nums[j] == current + 1) {
            int k = j;
            while (k < nums.size() && nums[k] == current + 1)
                k++;
            take += solve(k, nums);
        } else {
            take += solve(j, nums);
        }
        
        return dp[i] = max(take, skip);
    }
    
    int deleteAndEarn(vector<int>& nums) {

        /* 
        Well this somewhat looks likee house robber..
        Not i+1..to the last last house nor the i+2 and till the circular first house
        Sorting might be useful->nlogn
        [2,3.4] suppose if i take 2 then surely i cannot take any value which corresponds to
        2-1 or 2+1 and this will help in not taking the previous characters to check like
        there is no need for checking the 2-1 cause we are sorted. 

        So simple take not-take with a check for if(i+1<n && nums[i]!=nums[i+1]-1)
        No need to delete and all cause it will take so much of time 
        deleting an element takes O(n) separately  
     */   


        if (nums.empty())return 0;
        sort(nums.begin(), nums.end());
        dp.assign(nums.size(), -1);
        return solve(0, nums);
    }
};
