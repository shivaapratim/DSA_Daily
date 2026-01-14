class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
         
        vector<int>pre(prices.size(),0);
        pre[0]=1;

        for(int i=1; i<prices.size();i++){
            if(prices[i-1]-1 == prices[i]){
                pre[i]=1;
            }
        
        }

        long long ans=0;

        vector<int>cnt(prices.size(),0);
        cnt[0]=1;

        for(int i=1; i<pre.size(); i++){
            if(pre[i] == 1)
                cnt[i] = cnt[i-1] + 1;
            else
                cnt[i] = 1;
        }


        ans= accumulate(cnt.begin(),cnt.end(),0LL);


        return ans;
    }
};