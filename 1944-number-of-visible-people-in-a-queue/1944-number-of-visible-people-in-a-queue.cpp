class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        stack<int>st;
        vector<int>ans;

        for(int i=h.size()-1; i>=0; i--){
            int cnt=0;
            while(!st.empty() && h[i]>st.top()){
                st.pop();
                cnt++;
            }
            if(!st.empty())cnt++;

            st.push(h[i]);

            ans.push_back(cnt);
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};