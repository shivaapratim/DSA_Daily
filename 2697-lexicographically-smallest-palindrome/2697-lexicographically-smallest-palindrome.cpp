class Solution {
public:
    string makeSmallestPalindrome(string s) {
        string s1="";
        string s2="";
        int n=s.length();
        for(int i=0; i<n/2; i++){
            if(s[i]==s[n-i-1]){
                s1+=s[i];
                s2+=s[i];
            }
            else if(s[i]!=s[n-i-1]){
                char a;
                if(s[i]<s[n-i-1])a=s[i];
                else a=s[n-i-1];
                s1+=a;
                s2+=a;
            }
        }
        if(s.length()%2==1)s1+=s[n/2];
        reverse(s2.begin(),s2.end());
        return s1+s2;
    }
};