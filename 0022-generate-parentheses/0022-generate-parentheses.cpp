class Solution {
public:

    void solve(int o, int c, int n,string s ,vector<string>&result){
        if(s.length()==2*n){
            result.push_back(s);
            return;
        }
        if(o<n){
            solve(1+o,c,n,s+'(',result);
        }
        if(c<o){
            solve(o,1+c,n,s+')',result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string s="";
        solve(0,0,n,s,result);
        return result;
    }
};