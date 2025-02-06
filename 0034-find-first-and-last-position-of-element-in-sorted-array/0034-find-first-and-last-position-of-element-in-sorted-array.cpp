 int solveLast(vector<int>& nums, int target){
    int n=nums.size();
    int high=n-1;
    int low=0;
    int mid;
    int res=-1;
    while(low<=high){
        mid=(high+low)/2;
        if(nums[mid]==target){
            res=mid;
            low=mid+1;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
            
        }
    }
    return res;
}

int solveFirst(vector<int>& nums, int target){
    int n=nums.size();
    int high=n-1;
    int low=0;
    int mid;
    int res=-1;
    while(low<=high){
        mid=(high+low)/2;
        if(nums[mid]==target){
            res=mid;
            high=mid-1;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
 


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int ans2=solveLast(nums,target);
      int ans1=solveFirst(nums,target);
      vector<int>ans;
      ans.push_back(ans1);
       ans.push_back(ans2);
       return ans;
    }
};