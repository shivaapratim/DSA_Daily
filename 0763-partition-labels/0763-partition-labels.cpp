class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;

        for(int i=0; i<s.length(); i++){
           if(mp.find(s[i])!=mp.end()){
                mp[s[i]]=max(mp[s[i]],i);
           }
           else{
                mp.insert({s[i],i});
           }
        }

        int prev=-1;
        int maxi=0;

        vector<int>ans;

        for(int i=0; i<s.length(); i++){
            maxi=max(maxi,mp[s[i]]);
            if(maxi==i){
                ans.push_back(maxi-prev);
                prev=maxi;
            }
        }
        return ans;

    }
};