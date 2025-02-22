class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>arr;

        int i=0; int j=0;
        //Explicit
        while (j < k) {
            mp[nums[j]]++;
            j++;
        }
        arr.push_back(mp.rbegin()->first);

        while(j<nums.size()){
            mp[nums[j]]++;
            
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            arr.push_back(mp.rbegin()->first);
            i++;
            j++;
        }
        return arr;
    }
};