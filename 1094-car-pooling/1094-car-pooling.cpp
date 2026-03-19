class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>>arr;

        for(auto it: trips){
            arr.push_back({it[1],it[2],it[0]});
        }
        
        vector<pair<int,int>>events;

        for(auto it: arr){
            events.push_back({it[0],it[2]});
            events.push_back({it[1],-it[2]});
        }

        sort(events.begin(),events.end());
        

        int sum=0;

        for(auto it: events){
            sum+=it.second;
            if(sum>capacity){
                return false;
            }
        }
        return true;
    }
};