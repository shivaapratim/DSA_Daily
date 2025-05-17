class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>mp;
        sort(changed.begin(),changed.end());
        if(changed.size()%2==1)return {};

        for(auto it:changed){
            mp[it]++;
        }

        vector<int>ans;

        for(int i=0; i<changed.size();i++){
            if(mp[changed[i]]==0)continue;
            if(mp.find(changed[i]*2)==mp.end() || mp[changed[i]*2]==0){
                return {};
            }
            ans.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i]*2]--;
        }
        return ans;
    }
};