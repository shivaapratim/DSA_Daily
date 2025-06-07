class Solution {
public:

    bool isposs(const vector<int>&nums, int mid, int p){
        for(int i=0; i<nums.size()-1;){
            if((nums[i+1]-nums[i])<=mid){
                p--;
                i+=2;
            }
            else{
                i++;
            }
            if(p==0)return true;
        }

        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int s=0;
        sort(nums.begin(),nums.end());
        if(nums.size()==1)return 0;
        int e= (nums[nums.size()-1] - nums[0]);
        
        int ans=0;

        while(s<=e){
            int mid= s+(e-s)/2;

            if(isposs(nums,mid,p)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ans;

    }
};