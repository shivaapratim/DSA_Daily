 class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        
        int w=1;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' ')w++;
        }


        int curr = 0;
     
        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern[i];
            string temp = "";

            for (int j = curr; j < s.length(); j++) {
                if (s[j] == ' ') {
                    curr = j + 1;

                    break;
                }
                temp += s[j];
            }

            if (mp.find(ch) != mp.end()) {
                if (mp[ch] != temp) return false;
            } else {
                // **Extra check:** Ensure no other char is mapped to `temp`
                for (auto it : mp) {
                    if (it.second == temp) return false; 
                }
                mp[ch] = temp;
            }
        }
        if(pattern.length()!=w){
            return false;
        } 
        cout<<w;
        return true;
    }
};
