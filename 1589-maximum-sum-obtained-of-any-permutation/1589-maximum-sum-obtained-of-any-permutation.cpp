class Solution {
public:
    int MOD =1e9+7;

    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int>arr(nums.size(),0);

        for(auto it: requests){
            arr[it[0]]++;
            
            if(it[1]+1<nums.size())
            arr[it[1]+1]--;
        }

        for(int i=1; i<arr.size();i++){
            arr[i]+=arr[i-1];
        }

        sort(arr.begin(),arr.end());
        sort(nums.begin(),nums.end());

        int sum=0;

        for(int i=0; i<nums.size();i++){
            sum = (sum + ((1LL* arr[i]*nums[i])%MOD))%MOD; 
        }

        return sum;
    }
};