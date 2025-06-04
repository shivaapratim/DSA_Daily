class Solution {
public:
    char solve(int a, string &s1, string &s2) {
        // Initialize with the pair at index a.
        set<char> st;
        st.insert(s1[a]);
        st.insert(s2[a]);
        
        // Iteratively add new equivalent characters until no more can be added.
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < s1.length(); i++) {
                // If one character in the pair is in the set and the other isn't,
                // add the other character.
                if (st.find(s1[i]) != st.end() && st.find(s2[i]) == st.end()) {
                    st.insert(s2[i]);
                    changed = true;
                }
                if (st.find(s2[i]) != st.end() && st.find(s1[i]) == st.end()) {
                    st.insert(s1[i]);
                    changed = true;
                }
            }
        }
        
        // *st.begin() gives the lexicographically smallest element.
        return *st.begin();
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Build maps holding one (last) occurrence index for each character
        // in s1 and s2.
        map<char, int> mp1;
        map<char, int> mp2;
        for (int i = 0; i < s1.length(); i++) {
            mp1[s1[i]] = i;
        }
        for (int i = 0; i < s2.length(); i++) {
            mp2[s2[i]] = i;
        }
        
        string ans = "";
        for (char c : baseStr) {
            int a = s1.length();
            int b = s2.length();
            if (mp1.find(c) != mp1.end()) {
                a = mp1[c];
            }
            if (mp2.find(c) != mp2.end()) {
                b = mp2[c];
            }
            // If the character doesn't appear in either s1 or s2, it remains unchanged.
            if (a == s1.length() && b == s2.length()) {
                ans.push_back(c);
                continue;
            }
            // Choose the partner order based on the smaller index.
            if (min(a, b) == a) {
                ans.push_back(solve(a, s1, s2));
            } else {
                ans.push_back(solve(b, s2, s1));
            }
        }
        return ans;
    }
};
