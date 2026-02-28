class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;

        for(int i=0; i<nums.size();i++){
            
            int find_val= target-nums[i];

            if(mp.find(find_val)!=mp.end()){
                return {i,mp[find_val]};
            }

            mp.insert({nums[i],i});

        } 
         
        return {};
    }
};