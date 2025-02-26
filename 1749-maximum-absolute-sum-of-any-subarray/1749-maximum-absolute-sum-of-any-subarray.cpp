class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;

        int sum=0;

        for(int i=0; i<nums.size();i++){
            sum+=nums[i];
            if(sum>0)sum=0;
            mini=min(mini,sum);
        }

        sum=0;

        for(int i=0; i<nums.size();i++){
            sum+=nums[i];
            if(sum<0)sum=0;
            maxi=max(maxi,sum);
        }
        return max(abs(mini),maxi);
    }
};