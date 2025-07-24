#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Kept as a member variable as you had it, to be shared across recursive calls.
    int maxLen;

    // Your original check function. Note: This function is no longer needed with the
    // corrected divide-and-conquer logic, but I've left it here to show that
    // the new approach is a simplification of your original idea.
    bool check(unordered_map<char, int>& mp, int k) {
        for (auto it : mp) {
            if (it.second < k) return false;
        }
        return true;
    }

    // RENAMED from checkAgain for clarity, but this is the fixed version of that function.
    // It is now the main recursive worker function that correctly implements your goal.
    void solve(string s, int k) {
        // Base Case 1: If the string is shorter than k, no valid substring is possible.
        if (s.length() < k) {
            return;
        }

        // --- The "Divide" Step ---
        // First, find all characters in THIS substring 's' that will act as splitters.
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        set<char> st; // This will hold the "splitter" characters for the current string 's'.
        for (auto it : mp) {
            if (it.second < k) {
                st.insert(it.first);
            }
        }

        // Base Case 2: If 'st' is empty, it means every character in the current
        // string 's' appears at least k times. The whole string is valid.
        if (st.empty()) {
            maxLen = max(maxLen, (int)s.length());
            return; // Stop recursing down this path.
        }

        // --- The "Conquer" Step ---
        // If we get here, there are splitters in 'st'. We must break 's' apart
        // and recursively call solve() on the pieces.
        int i = 0;
        for (int j = 0; j < s.length(); j++) {
            // If the character s[j] is a splitter
            if (st.count(s[j])) {
                // Then the segment from i to j-1 is a subproblem to solve.
                if (j > i) {
                    solve(s.substr(i, j - i), k);
                }
                // The next potential segment starts after the splitter.
                i = j + 1;
            }
        }

        // After the loop, we must handle the final segment after the last splitter.
        // For example, in "abacaba" with splitter 'c', we handle "aba" in the loop,
        // and this line handles the final "aba".
        if (i < s.length()) {
            solve(s.substr(i), k);
        }
    }

    int longestSubstring(string s, int k) {
        // Initialize the result for each new run.
        maxLen = 0;
        // Start the recursive process on the entire initial string.
        solve(s, k);
        return maxLen;
    }
};
