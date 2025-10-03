class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=numBottles;
        int left=numBottles;

        while(left>=numExchange){
            int drank= left/numExchange;
            left=left%numExchange;
            sum+=drank;
            left=drank+left;
        }
        return sum;
    }
};