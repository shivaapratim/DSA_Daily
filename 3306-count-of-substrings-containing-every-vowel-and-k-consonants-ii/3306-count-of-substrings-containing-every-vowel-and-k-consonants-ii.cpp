 
class Solution {
public:
    // Helper: returns true if the character is a vowel.
    bool isvowel(char s) {
        return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u');
    }

    /*
      This function counts the number of substrings in "word" that contain:
        - All 5 vowels at least once.
        - Exactly k consonants.
      
      It uses:
       • A precomputed vector "cons" so that cons[i] is the index of the next consonant from i (or word.size() if none remains).
       • A sliding window [i, j] that tracks:
            - A frequency map "mp" for vowels.
            - "num_cons" for the count of consonants.
       • When the window is valid (mp.size()==5 and num_cons==k), it counts all valid extensions.
    */
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<int> cons(n);
        int considx = n;
        // Precompute the next consonant index for every position.
        for (int i = n - 1; i >= 0; i--) {
            if (!isvowel(word[i])) {
                cons[i] = i; 
                considx = i;
            } else {
                cons[i] = considx;
            }
        }
        
        int i = 0, j = 0;
        unordered_map<char, int> mp; // frequency map for vowels in the window.
        int num_cons = 0;            // counts consonants in the window.
        long long ans = 0;           // accumulator for the answer.

        while (j < n) {
            // Expand window: add word[j]
            if (isvowel(word[j])) {
                mp[word[j]]++;
            } else {
                num_cons++;
            }
            
            // --- FIX 1: If the window has more consonants than k, shrink it.
            while (i <= j && num_cons > k) {
                if (isvowel(word[i])) {
                    mp[word[i]]--;
                    if (mp[word[i]] == 0)
                        mp.erase(word[i]);
                } else {
                    num_cons--; // removing a consonant.
                }
                i++;
            }
            
            // --- FIX 2 & 3: When the window is valid (exactly k consonants and all 5 vowels),
            // count all valid extensions. (If the end character is a vowel, extension count is cons[j]-j.
            // If consonant, add 1 to count the current ending itself.)
            while (i <= j && mp.size() == 5 && num_cons == k) {
                int extension = 0;
                if (isvowel(word[j]))
                    extension = cons[j] - j;         // extend until a new consonant appears.
                else
                    extension = cons[j] - j + 1;       // j itself is a consonant; count it.
                ans += extension;
                
                // Remove the leftmost element from the window (using the proper map key):
                if (isvowel(word[i])) {
                    mp[word[i]]--;
                    if (mp[word[i]] == 0)
                        mp.erase(word[i]);
                } else {
                    num_cons--;
                }
                i++;
            }
            
            j++; // continue expanding the window.
        }
        
        return ans;
    }
};
