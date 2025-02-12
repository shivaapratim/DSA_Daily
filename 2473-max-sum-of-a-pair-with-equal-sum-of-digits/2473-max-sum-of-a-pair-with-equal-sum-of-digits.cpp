class Solution {
public:

    int getD(int n){
        int sum=0;

        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        // map<int, multiset<int>> mp; // Use multiset to keep elements sorted also allow duplicates
        // int n = nums.size();

        // for (int i = 0; i < n; i++) {
        //     string s = to_string(nums[i]);
        //     int p = 0;
        //     for (char c : s) {
        //         p += c - '0';
        //     }
        //     mp[p].insert(nums[i]);
        // }

        // int ans = -1;

        // for (auto &it : mp) {
        //     if (it.second.size() >= 2) {
        //         auto iter = it.second.rbegin(); 
        //         int first = *iter;
        //         iter++;
        //         int second = *iter;

        //         ans = max(ans, first + second);
        //     }
        // }

        // return ans;


        unordered_map<int,int>mp;
        int maxi=-1;
        for(int i=0; i<nums.size();i++){
            int n = getD(nums[i]);
            
            if(mp.count(n)){
                maxi=max(maxi,nums[i]+mp[n]);
            }
            mp[n]=max(mp[n],nums[i]);
            
        }
        return maxi;
    }
};