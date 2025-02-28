class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        //pair-> {distance, vector<int>}
        // priority_queue<pair<int,vector<int>>, pair<int,vector<int>>, greater<pair<int,vector<int>>>>pq;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

        for(auto it : points){
            int area= sqrt((it[0]*it[0])+(it[1]*it[1]));
            pq.push({area,it});
        }
        int n=0;

        while(!pq.empty() && n<k){
            ans.push_back(pq.top().second);
            pq.pop();
            n++;
        }
        return ans;
    }
};