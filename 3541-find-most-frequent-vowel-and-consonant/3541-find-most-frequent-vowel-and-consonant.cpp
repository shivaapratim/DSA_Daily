class Solution {
public:
    int maxFreqSum(string s) {
        int freqVowel=0;
        int freqCons=0;

        unordered_set<int>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        unordered_map<char,int>v;
        unordered_map<char,int>c;

        for(int i=0; i<s.length();i++){
            if(st.find(s[i])!=st.end()){
                v[s[i]]++;
            }
            else{
                c[s[i]]++;
            }
        }
        
        for(auto it:v){
            freqVowel=max(freqVowel,it.second);
        }

        for(auto it:c){
            freqCons=max(freqCons,it.second);
        }

        return freqVowel+freqCons;
    }
};