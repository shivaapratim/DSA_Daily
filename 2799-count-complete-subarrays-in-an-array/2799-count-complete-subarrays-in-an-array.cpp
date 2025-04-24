class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>st;
        unordered_map<int,int>mp;

        for(auto it: nums){
            st.insert(it);
        }

        int i=0; int j=0; int n=nums.size(); int cnt=0; int ans=0; int elements=st.size();

        while(j<n){
            if(mp.find(nums[j])==mp.end()){
                cnt++;
            }
            mp[nums[j]]++;

            while(i<=j && cnt==elements){
                ans+=n-j;
                if(mp[nums[i]]-1==0){
                    cnt--;
                    mp.erase(nums[i]);
                }
                else mp[nums[i]]--;
                i++;
            }
            j++;
        }

        return ans;
    }
};