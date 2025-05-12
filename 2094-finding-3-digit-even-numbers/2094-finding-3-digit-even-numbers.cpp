class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        
        for (int i = 100; i < 1000; i++) {
            if (i % 2 != 0) continue;  
            
            bool isValid = true;
            unordered_map<int, int> digitCount;
            
            // Count the frequency of each digit in the input array
            for (int digit : digits) {
                digitCount[digit]++;
            }
            
            // Check if we can form the current number i
            string numStr = to_string(i);
            for (char c : numStr) {
                int digit = c - '0';
                if (digitCount.find(digit) == digitCount.end() || digitCount[digit] <= 0) {
                    isValid = false;
                    break;
                }
                digitCount[digit]--;
            }
            
            if (isValid) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};