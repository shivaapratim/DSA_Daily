class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
       //To filter elements
       set<int>st;

       for (int j = 0; j < triplets.size(); j++) {
            for (int i = 0; i < triplets[j].size(); i++) {
                if (triplets[j][i] > target[i]) {
                    st.insert(j);
                    break;  // No need to check further for this triplet
                }
            }
        }
       
        for(int i=0; i<3;i++){
            int maxi=INT_MIN;
            for(int j=0; j<triplets.size();j++){
                if(st.find(j)!=st.end())continue;
                maxi= max(maxi,triplets[j][i]);
            }
            if(maxi!=target[i])return false;  
        }
        return true;
    }
};