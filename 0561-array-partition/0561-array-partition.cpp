class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        //1 2 3 4

        int sum=0;
        int n= nums.size();
        for(int i=0; i<n; i+=2){
            sum+=nums[i];
        }
        return sum;
    }
};