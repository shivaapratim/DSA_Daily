class Solution {
public:
    long long coloredCells(int n) {
        //4(n-1)

        long long sum=1;

        for(int i=2; i<=n; i++){
            sum+= 4*(i-1);
        }

        return sum;
    }
};