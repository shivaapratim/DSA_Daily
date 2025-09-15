class Solution {
public:
    int canBeTypedWords(string s, string brokenLetters) {
        int canPrint=1;

        for(int i=0; i<s.length();i++){ 
            if(s[i]==' '){
                canPrint++;
            }
        }

        unordered_set<char>st;

        for(auto it: brokenLetters){
            st.insert(it);
        }

        int i=0;
        while(i<s.length()){
            if(st.find(s[i])!=st.end()){
                canPrint--;
                int j=i;
                while(j<s.length()){
                    if(s[j]==' '){
                        break;
                    }
                    j++;
                }
                i=j;
            }

            i++;
        }

        return canPrint;
    }
};