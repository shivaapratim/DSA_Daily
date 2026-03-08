class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0; i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];

                if(sum<0)j++;
                else if(sum>0)k--;
                else if(sum==0){
                ans.push_back({nums[i],nums[j],nums[k]});
                
                int s=j;
                while(j<k && nums[j]==nums[s])j++;
                s=k;
                while(j<k && nums[k]==nums[s])k--;
                }
            }
        }
        return ans;
    }
};