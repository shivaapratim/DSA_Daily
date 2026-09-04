class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>mini(nums.size());
        vector<int>maxi(nums.size());

        int mi=INT_MAX;
        int ma=INT_MIN;

        for(int i=0; i<nums.size();i++){
            ma=max(nums[i],ma);
            maxi[i]=ma;
        }
        for(int i=nums.size()-1; i>=0;i--){
            mi=min(nums[i],mi);
            mini[i]=mi;
        }

        int idx=-1;

        for(int i=0; i<nums.size();i++){
            if(maxi[i]-mini[i] <=k ){
                return i;
            }
        }

        return idx;
    }
};