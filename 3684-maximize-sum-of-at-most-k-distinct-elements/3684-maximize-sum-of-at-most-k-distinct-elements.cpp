class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int>st;

        for(int i=0; i<nums.size();i++){
            st.insert(nums[i]);
        }

        vector<int>ans;

        while (k>0 && !st.empty()) {
            auto it = prev(st.end()); 
            ans.push_back(*it);
            st.erase(it);  
            k--;            
        }

        return ans;
    }
};