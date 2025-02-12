class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, multiset<int>> mp; // Use multiset to keep elements sorted
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            int p = 0;
            for (char c : s) {
                p += c - '0';
            }
            mp[p].insert(nums[i]);
        }

        int ans = -1;

        for (auto &it : mp) {
            if (it.second.size() >= 2) {
                auto iter = it.second.rbegin(); 
                int first = *iter;
                iter++;
                int second = *iter;

                ans = max(ans, first + second);
            }
        }

        return ans;
    }
};