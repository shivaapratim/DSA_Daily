class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        // vector<int>ans;
        vector<int>asc;
        vector<int>desc;
        int q=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]<pivot){
                asc.push_back(nums[i]);
            }
            else if(nums[i]==pivot)q++;
            else{
                desc.push_back(nums[i]);
            }
        }

        vector<int>ans=asc;
        
        for(int i=0; i<q;i++){
            ans.push_back(pivot);
        }

        for(auto it:desc){
            ans.push_back(it);
        }

        return ans;
    }
};