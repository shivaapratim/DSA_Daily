class Solution {
public:
    string robotWithString(string s) {
        //We need a sorted map.
        map<char,int>mp;

        for(int i=0; i<s.length();i++){
            mp[s[i]]++;
        }

        string t="";
        string ans="";
        int i=0;

        while(i<s.length() || !t.empty()){
            if(t.length()!=0){
                while(!t.empty() && (mp.empty() || t[t.length()-1] <= mp.begin()->first)){
                    ans+=t[t.length()-1];
                    t.erase(t.length()-1,1);
                }
            }
            if(i<s.length()){
                t+=s[i];
                mp[s[i]]--;
                if(mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        return ans;
    }
};