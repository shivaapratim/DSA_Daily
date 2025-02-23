class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>st;
        int n=t.size();
        vector<int>ans(n,0);

        for(int i=n-1; i>=0; i--){
            while(!st.empty()&&t[i]>=t[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=st.top()-i;//days
            }
            st.push(i);
        }
        return ans;
    }
};