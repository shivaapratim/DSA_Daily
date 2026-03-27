class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>arr(n,0);
        for(auto& b: bookings){
            int u=b[0]-1;
            int v=b[1]-1;
            int wt=b[2];

            arr[u]+=wt;

            if(v+1<n)
            arr[v+1]-=wt;
        }

        for(int i=1; i<n; i++){
            arr[i]+=arr[i-1];
        }

        return arr;
    }
};