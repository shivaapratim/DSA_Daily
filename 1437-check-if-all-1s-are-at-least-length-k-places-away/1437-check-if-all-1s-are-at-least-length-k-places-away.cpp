class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev=0;
        int j=0;

        while(j<nums.size() && nums[j]!=1){
            j++;
        }
        prev=j;

        for(int i=j+1; i<nums.size();i++){
            if(nums[i]==1 && (i-prev-1)<k)return false;

            if(nums[i]==1)prev=i;
        }
        return true;
    }
};