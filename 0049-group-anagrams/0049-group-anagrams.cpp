class Solution {
public:
    //Mast likhe ho bas likhte likhte optimise krna bhool gye ... plus unordered map ka thoda glt upyog kiya hai 
    //har baar temp vahi same value ke liye point karega change hi nahi hoga so take a vector string

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<string>xd=strs;
    //     unordered_map<string,string>mp;
    //     for(string&i:xd){
    //         string temp=i;
    //         sort(i.begin(),i.end());
    //         mp[i]=temp;
    //     }
    //     sort(xd.begin(),xd.end());
    //     vector<vector<string>>s;
    //     int j=0;
    //     while(j<xd.size()){
    //         vector<string>t;
    //         while(j<xd.size()-1 && xd[j]==xd[j+1]){
    //             t.push_back(mp[xd[j]]);
    //             j++;
    //         }
    //         t.push_back(mp[xd[j]]);
    //         s.push_back(t);
    //         j++;
    //     }
    //     return s;
    
    
        // Instead of string->string, we need string->vector<string>
        unordered_map<string, vector<string>> mp;
       
        for(string& s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());   
            mp[sorted].push_back(s);
        }
        
         
        vector<vector<string>> result;
        for(auto& pair : mp) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};