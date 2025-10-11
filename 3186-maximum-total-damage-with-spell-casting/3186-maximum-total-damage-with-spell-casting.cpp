#define ll long long
class Solution {
public:
    vector<ll> a;
      map<ll,ll> mp;
    int n ;
    ll dp[100006];
    ll calc(int pos)
    {
        if(pos>=n)
            return 0;
        if(dp[pos]!=-1)
            return dp[pos];
        int next  = n+5;
        if(pos+1<n)
        {
            ll dif = a[pos+1]-a[pos];
            if(dif>2)
            {
                next = pos+1;
            }
            else if(dif==1)
            {
                if(pos+2<n)
                {
                    if(a[pos+2]==a[pos+1]+1)
                        next = pos+3;
                    else
                        next= pos+2;
                }
                    
            }
            else
                next = pos+2;
                
        }
        ll take = mp[a[pos]]*a[pos] + calc(next);
        ll ntake = calc(pos+1);
        return dp[pos]=max(take,ntake);
    }
    long long maximumTotalDamage(vector<int>& power) {
    
        
        memset(dp,-1,sizeof(dp));
        for(auto it:power)
            mp[it]++;
        for(auto it:mp)
            a.push_back(it.first);
        n = a.size();
        return calc(0);
        
    }
};