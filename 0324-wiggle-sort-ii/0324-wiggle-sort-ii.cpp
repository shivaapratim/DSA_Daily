#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sortedNums = nums;  
        sort(sortedNums.begin(), sortedNums.end()); 
        
        int n = nums.size();
        int mid = (n + 1) / 2;   

        int left = mid - 1;   
        int right = n - 1;    

         
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = sortedNums[left--];  
            } else {
                nums[i] = sortedNums[right--];  
            }
        }
    }
};
