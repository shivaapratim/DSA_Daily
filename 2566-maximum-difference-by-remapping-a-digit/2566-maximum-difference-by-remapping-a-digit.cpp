class Solution {
public:

    void solve(char to_change, string&s, char num){
        for(int i=0; i<s.length();i++){
            if(s[i]==num){
                s[i]=to_change;
            }
        }
    }

    int minMaxDifference(int num) {
        string mini = to_string(num);
        string maxi = to_string(num);

        solve('0',mini,mini[0]);

        for(int i=0; i<maxi.length(); i++){
            if(maxi[i]=='9')continue;
            else{
                solve('9',maxi,maxi[i]);
                break;
            }
        }

        return stoi(maxi)-stoi(mini);

    }
};