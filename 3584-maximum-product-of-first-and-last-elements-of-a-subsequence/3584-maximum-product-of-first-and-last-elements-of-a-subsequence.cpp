class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n= nums.size();

        if(m==1){
            long long ans=LLONG_MIN;
            for(int x: nums){
                ans=max(ans,(long long)x*x);
                
            }return ans;
        }

        vector<int>pos_max(n),neg_min(n);
        pos_max[0]=nums[0];
        neg_min[0]=nums[0];

        for(int i=1; i<n; i++){
            pos_max[i]= max(nums[i],pos_max[i-1]);
            neg_min[i]= min(nums[i],neg_min[i-1]);
        }

        long long ans=LLONG_MIN;

        for(int i=m-1; i<nums.size(); i++){
            if(nums[i]<0){
                long long poss= ((long long)neg_min[i-m+1]*nums[i]); 
                ans = max(poss , ans);
            }
            else{
                long long poss= ((long long)pos_max[i-m+1]*nums[i]);
                ans= max(poss, ans);
            }
        }

         
        return ans;
    }
};