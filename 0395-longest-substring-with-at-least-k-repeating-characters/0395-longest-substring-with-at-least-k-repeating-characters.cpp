#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // This helper function now checks if a pre-computed frequency map is valid.
    // A map is valid if every character count in it is at least k.
    bool isValid(const unordered_map<char, int>& countMap, int k) {
        // Check if every character in the map meets the k-frequency requirement.
        for (auto const& [key, val] : countMap) {
            if (val < k) {
                return false; // Found a character with frequency less than k.
            }
        }
        
        return true; // All characters appeared at least k times.
    }

    int longestSubstring(string s, int k) {
        int maxLen = 0;
        int n = s.length();

        // The outer loop determines the starting point of the window.
        for (int i = 0; i < n; i++) {
            // For each starting point 'i', we initialize a frequency map
            // and expand the window to the right.
            unordered_map<char, int> countMap;
            
            // The inner loop expands the window from 'i' to the end of the string.
            for (int j = i; j < n; j++) {
                // Add the new character s[j] to our current window's frequency map.
                countMap[s[j]]++;

                // A small optimization: if the current window is not even as long
                // as our current max length, there's no point in checking it.
                if ((j - i + 1) <= maxLen) {
                    continue;
                }
                
                // Check if the current window defined by countMap is valid.
                if (isValid(countMap, k)) {
                    // If it's valid, update our maximum length.
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
