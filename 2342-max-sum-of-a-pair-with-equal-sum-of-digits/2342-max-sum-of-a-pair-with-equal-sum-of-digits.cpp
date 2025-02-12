class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> mp;  // Changed to vector instead of pair<int,set>
        
        // Calculate digit sum for each number and store
        for(int num : nums) {
            int digitSum = 0;
            for(char c : to_string(num)) {
                digitSum += c - '0';
            }
            mp[digitSum].push_back(num);
        }
        
        int maxSum = -1;
        
         
        for(auto& [digitSum, numbers] : mp) {
            if(numbers.size() >= 2) {
                sort(numbers.begin(), numbers.end(), greater<int>());
                maxSum = max(maxSum, numbers[0] + numbers[1]);
            }
        }
        
        return maxSum;
    }
};