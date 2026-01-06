class Solution {
public:
    typedef long long ll;

    long long appealSum(string s) {

        ll n=s.length();
        ll ans=0;

        for(char ch='a'; ch<='z'; ch++){
            int last=-1;
            ll contribution= n*(n+1)/2;
            for(int i=0; i<n;i++){
    
                if(s[i]==ch){
                    ll lengthBetween= i-last-1;

                    // Total - Length where this ch was not present
                   
                    if(lengthBetween>0){
                        contribution-= lengthBetween*(lengthBetween+1)/2; 
                    } 
                    
                    last=i;
                }
            }

            ll len=n-last-1;
            if(len>0){
                contribution-=len*(len+1)/2;
            }
            ans+=contribution;
        }

        return ans;   
    }
};