class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>>pq;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto &it:mp){
            pq.push({it.second,it.first});
        }
        int i=0;
        vector<int>arr;
        while(!pq.empty()){
            if(i==k)break;
            arr.push_back(pq.top().second);
            pq.pop();
            i++;
        }
        
        return arr;
    }
};