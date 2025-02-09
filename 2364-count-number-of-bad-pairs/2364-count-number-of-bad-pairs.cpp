class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        //It means-> nums[i]-i!=nums[j]-j

        //But if u count bad, u will have to use O(n^2) anyhow!

        //So first count the good and then from total...-good=bad

        long long countGood=0;

        unordered_map<int,int>mp;

        for(int i=0; i<nums.size();i++){
            mp[nums[i]-i]++;
        }

        for(auto it: mp){
            long long s=it.second;
            countGood+=(long long)s*(s-1)/2;
        }

        long long total_comb= (long long)nums.size()*(nums.size()-1)/2;
        
        return total_comb-countGood;
    }
};