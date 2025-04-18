class Solution {
public:

    void solve(string&s, int n){
        if(n==0){
            return;
        }

        string str="";
        int cnt=1;
        for(int i=0; i<s.size(); i++){
            if(i+1<s.size() && s[i]==s[i+1]){
                cnt++;
            }
            else{
                str = str + to_string(cnt) + s[i];
                cnt=1;
            }
        }
        s=str;
        solve(s,n-1);
    }

    string countAndSay(int n) {
        string s="1";
        if(n==1)return s;
        solve(s,n-1);
        return s;
    }
};