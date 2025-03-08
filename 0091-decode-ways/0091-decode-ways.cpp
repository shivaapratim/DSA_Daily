class Solution {
public:

    //Map use to store all alphabets-> not needed cause we just need counts.
    //Not to take more than 2 digits, as s can max be equal to 100 which gives 1 0 0 
    // If we somewhere find a split with 0 in first place then dont count it.-> temp[0]==0
    //Or u can also use string->char, so if "06" appears then it will not be in the map.

    //Baaki end tak pohoch ke jitni mapping bn jaaye vo return kar do
    //If match possible means we reached till out of boundary means we made it.
    //Acha here we have to take all the occurences, so pick not pick at a point will
    //not just be sufficient cause we have to decode for the entire string without skipping
    //Any of the values 
    
    // It's simple-> For every i it has two choices either to add with the string 
    //Or start a new from there and leave the previous to give an answer.
    //Suppose for "1106"-> We can take 1 then explore for i=1 which has 2 choices add
    //with previous 1 or start a new from there , that is '1' or '11', this also gives us hints
    //For dp as we have computed the answer for 1 we can just return it if the i=1 1 wants to go
    //By its own.

    //Ex-> 276 split from 2 or take 27 but 27 is out of range, and u cannot take 276 because its 3 digit
    //Also we cannot break it like 76 because this is also out of range
    //Toh base case bohot dhyaan se likhna

    //solve(i+1)..1 length   solve(i+2)..2 length
    //But solve(i+2) is only possible if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')

    // int dp[101];

    // int solve(int i, string&s){
    //     if(i>=s.length()){
    //         //Means reached a valid split
    //         return 1; //1 valid split found
    //     }
    //     if(s[i]=='0'){
    //         return 0;
    //     }

    //     if(dp[i]!=-1)return dp[i];
        
    //     int take1=solve(i+1,s);
    //     int take2=0;
    //     //Check for out of bound also
    //     if((i+1<s.length()) && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6'))){
    //         take2=solve(i+2,s);
    //     }
    //     return dp[i]=take1+take2;
    // }

    // int numDecodings(string s) {
    //     memset(dp,-1,sizeof(dp));
    //     return solve(0,s);
    // }

    int numDecodings(string s) {
        int n=s.length();
        
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='0'){
                dp[i]=0;
            }
            else{
                dp[i]=dp[i+1]; //solve(i+1) Always take1

                if( (i+1<n) && (s[i]=='1' || (s[i]=='2' && s[i+1]<='6') ) ){
                    dp[i]+=dp[i+2]; //solve(i+2) ->take1+take2
                }
            }
        }
        return dp[0];

    }
};