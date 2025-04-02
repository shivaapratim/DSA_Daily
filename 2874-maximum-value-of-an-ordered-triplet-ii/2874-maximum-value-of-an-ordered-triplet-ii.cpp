class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //Since i can be the left side, which can be max
        //and k will always be max to multiply with, which is in right
        // Only j is variable so we can leverage the concept of prefix array where
        //We can take the max of the left and the right at each point.

        int n=nums.size();

        vector<int>l(n,0),r(n,0);

        long long maxSum=0;

        l[0]=nums[0];
        r[n-1]=nums[n-1];

        for(int i=1; i<n; i++){
            l[i]= max(l[i-1],nums[i]);
        }

        for(int i=n-2; i>=0; i--){
            r[i]= max(r[i+1],nums[i]);
        }

        for(int i=1; i<n-1; i++){
            
            long long sum= (long long)(l[i-1]-nums[i])*r[i+1];  
            
            maxSum= max(maxSum,sum); 
        }

        return maxSum;

    }
};