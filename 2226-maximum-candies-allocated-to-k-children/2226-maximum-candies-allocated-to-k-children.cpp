class Solution {
public:

    bool candis(vector<int>&candies,int mid, int k){
        long long cnt=0;

        for(int i=0; i<candies.size();i++){
            cnt+=candies[i]/mid;
            if(cnt>=k)return true;
        }
        return cnt>=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int s=1;
        int e=*max_element(candies.begin(),candies.end());
        int result=0;
        while(s<=e){
            int mid= s+(e-s)/2;

            if(candis(candies,mid,k)){
                result=mid;
                s=mid+1;
            }
            else
            e=mid-1;
        }
        return result;
    }
};