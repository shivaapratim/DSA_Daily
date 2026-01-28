class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();

        int mini=*max_element(arr.begin(),arr.end()) - *min_element(arr.begin(),arr.end());

        vector<vector<int>>ans;

        for(int i=0;i<n-1; i++){
            mini= min(mini,abs(arr[i+1] - arr[i]));
        }

        for(int i=0; i<n-1; i++){
            if(abs(arr[i+1]-arr[i]) == mini){
                ans.push_back({arr[i],arr[i+1]});
            }
        }

        return ans;

    }
};