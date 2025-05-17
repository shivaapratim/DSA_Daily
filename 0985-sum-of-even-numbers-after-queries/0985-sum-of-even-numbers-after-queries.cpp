class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;

        for(int i=0; i<nums.size();i++){
            if(nums[i]%2==0)sum+=nums[i];
        }

        vector<int>ans;

        for(auto it: queries){
            int a=it[0];
            int b=it[1];

            if(nums[b]%2==0){// Agar pehle se contribute krta hai 
                sum-=nums[b];
            }

            nums[b]+=a;
            if(nums[b]%2==0){
                sum+=nums[b];
               
            }
            ans.push_back(sum);
        } 
        

        return ans;
    }
};