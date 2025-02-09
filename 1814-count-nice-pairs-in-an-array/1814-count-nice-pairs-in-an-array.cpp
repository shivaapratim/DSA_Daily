class Solution {
public:
    int MOD=1e9+7;

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(int i=0; i<nums.size();i++){
            string rev= to_string(nums[i]);
            reverse(rev.begin(),rev.end());
            int irev= stoi(rev);
            mp[nums[i]-irev]++;
        }

        int good=0;
        for(auto it: mp){
            long long a=it.second;
            long long s=((a*(a-1))/2)%MOD;
            good= (good+s)%MOD;
        }
        return good;
    }
};