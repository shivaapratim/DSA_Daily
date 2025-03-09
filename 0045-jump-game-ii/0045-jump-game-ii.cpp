class Solution {
public:

    void solve(int i, vector<int>&nums,int&mini, int cnt){
        if(i==nums.size()-1){
            mini= min(cnt,mini);
            return;
        }

        if(i>=nums.size())return;
        
        if(nums[i]==0)return;

        for(int j=1; j<=nums[i] && j<nums.size(); j++){
            solve(i+j,nums,mini,cnt+1);
        }

    }

    int jump(vector<int>& nums) {
        int mini=nums.size();
        int cnt=0;
        solve(0,nums,mini,cnt);
        return mini;
    }
};