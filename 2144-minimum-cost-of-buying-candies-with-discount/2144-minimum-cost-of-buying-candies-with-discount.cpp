class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.begin(),cost.end());
        
        int minSum=0;
        int temp=0;
        for(int i=cost.size()-1; i>=0; i--){
            if(temp==2){
                temp=0;
                continue;
            }
            temp++;
            minSum+=cost[i];
        }
        return minSum;

    }
};