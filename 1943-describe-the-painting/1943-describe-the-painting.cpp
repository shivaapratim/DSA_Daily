class Solution {
public:
    typedef long long ll;

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<ll,ll>mp;

        for(auto it: segments){
            int start= it[0];
            int end= it[1];
            int color= it[2];

            mp[start]+=color;
            mp[end]-=color;
        }

        vector<vector<ll>>ans;
        auto it= mp.begin();
        ll start = it->first;
        ll sum= it->second;
        it++;

        while(it!=mp.end()){
            if(sum>0){
                ans.push_back({start,it->first,sum});
            }
            start=it->first;
            sum+=it->second;
            it++;
        }
        return ans;
    }
};