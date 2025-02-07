class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        unordered_map<int,int>st;
        vector<int>res;
        int dis=0;

        for(auto it: queries){
            int a= it[0];
            int b= it[1];

            //Ise bolte hain lazy inclination we only put the element in map when iterated.
            if (mp.find(a) == mp.end()) {
                mp[a] = 0;
            }

            if(mp[a]==0){
                if(st[b]==0){
                    st[b]++;
                    mp[a]=b;
                    dis++;
                }
                else{
                    st[b]++;
                    mp[a]=b;
                }
            }
            else{
                st[mp[a]]--;
                if(st[mp[a]]==0){
                    dis--;
                }   
                if(st[b]==0){
                    st[b]++;
                    dis++;
                }
                else{
                    st[b]++;
                }
                mp[a]=b;
            }
            res.push_back(dis);
        }
        return res;
    }
};