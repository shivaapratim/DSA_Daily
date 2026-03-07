class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int N= prices.size();
        // int maxi=0;
        // int mini=prices[0];
        // int diff=0;
        // for(int i=1; i<N; i++){
        //     diff= prices[i]-mini;
        //     maxi= max(diff,maxi);
        //     mini=min(prices[i],mini);
        // }
        // return maxi;

        int n=prices.size();
        int a=0;
        int m=0;
        if(prices.size()==1)return 0;
        for(int i=1; i<n; i++){
            a+=prices[i]-prices[i-1]; // 5, 3  
            if(a<0){
                a=0;
            }
            m=max(m,a);
        }
        return m;
    }
};