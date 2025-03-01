class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        vector<int>arr;
        int cnt=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>0)arr.push_back(nums[i]);
            else cnt++;
        }

        for(int i=1; i<=cnt; i++){
            arr.push_back(0);
        }

        return arr;
    }
};