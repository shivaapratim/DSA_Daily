class Solution {
public:

    bool isprime(int n){
        if(n==1)return false;

        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0)return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<vector<int>>ans;

        int num1=0;
        int num2=0;

        for(int i=left; i<=right; i++){
            if(isprime(i)){
                num1=i;
                break;
            }
        }
        if(num1==0)return{-1,-1};

        for(int i=num1+1; i<=right; i++){
            if(isprime(i)){
                num2=i;
                int diff= num2-num1;
                ans.push_back({diff,num1,num2});
                num1=num2;
            }
        }

        sort(ans.begin(),ans.end());

        if(ans.size() == 0) return {-1, -1};
        // if(ans.size()>0 && ans[0][1]>0 && ans[0][2]>0){
        return {ans[0][1],ans[0][2]};
        // }
        // return {-1,-1};
    }
};