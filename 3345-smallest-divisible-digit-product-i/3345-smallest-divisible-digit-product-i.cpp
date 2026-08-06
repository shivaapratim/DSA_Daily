class Solution {
public:

    int check(int n, int t){
        int prod=1;
        while(n){
            prod*=n%10;
            n/=10;
        }
        
        return prod%t == 0 ? 0 : 1;
    }

    int smallestNumber(int n, int t) {
        for(int i=n; i<=100; i++){
            if(check(i,t)==0){
                return i;
            }
        }
        return -1;
    }
};