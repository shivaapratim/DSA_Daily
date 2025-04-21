class Solution {
public:

    int longestSubsequence(vector<int>& arr, int difference) {
        // return solve(INT_MIN,0,arr,difference);
        int n=arr.size();
        int maxlen=1;
        vector<int>t(n+1,1);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i]-arr[j]==difference){
                    t[i] = max(t[i],1+t[j]);
                    maxlen=max(maxlen,t[i]);
                }
            }
        }
        return maxlen;
    }
};