class Solution {
public:

    bool solve(int i, int n){
        if(n==0){
            return true;
        }
        if(n<0 || pow(3, i) > n){
            return false;
        }

        return solve(i+1,n-(int)pow(3,i)) || solve(i+1,n);

    }

    bool checkPowersOfThree(int n) {
        return solve(0,n);
    }
};