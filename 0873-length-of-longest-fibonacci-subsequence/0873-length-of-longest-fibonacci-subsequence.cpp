class Solution {
public:

    int solve(vector<int>&arr, int j, int k, unordered_map<int,int>&mp){
        int target=arr[k]-arr[j];
        if(mp.count(target) && mp[target]<j){
            int i=mp[target];
            return solve(arr,i,j,mp)+1;
        }
        return 2;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0; i<arr.size();i++){
            mp[arr[i]]=i;
        }

        int maxlen=0;
        for(int j=1; j<arr.size();j++){
            for(int k=j+1; k<arr.size();k++){
                int length=solve(arr,j,k,mp);
                if(length>2)
                maxlen=max(length,maxlen);
            }
        }
        return maxlen;
    }
};