class Solution {
public:
    // Note: pass the map by reference so that removals persist.
    bool ispossible(map<int, int>& mp, int k) {
        // Instead of starting at 1 unconditionally, find the smallest number available.

        int start = mp.begin()->first;
        
        
        // Try to remove a group of k consecutive numbers starting from 'start'
        for (int i = start; i < start + k; i++) {
            // If any of the required consecutive numbers is missing, the removal fails
            if (mp.find(i) == mp.end()) {
                return false;
            }
            // Decrement the count for this number
            mp[i]--;
            if (mp[i] == 0) {
                mp.erase(i);
            }
        }
        return true;
    }
    
    bool isPossibleDivide(vector<int>& nums, int k) {
        // If total number of elements is not divisible by k, it's impossible.
        if (nums.size() % k != 0) return false;
        
        map<int,int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        
        // The number of groups to be formed.
        int groups = nums.size() / k;
        
        // For each group, attempt to remove a set of k consecutive numbers.
        for (int i = 0; i < groups; i++) {
            if (!ispossible(mp, k))
                return false;
        }
        
        return true;
    }
};
