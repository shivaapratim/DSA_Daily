class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());

        if(word1.length()!=word2.length())return false;
 

        for(int i=0; i<word1.length();i++){
            freq1[word1[i]-'a']++;
        }
        for(int i=0; i<word2.length();i++){
             freq2[word2[i]-'a']++;
        }

        for(int i=0; i<26;i++){
            if(freq1[i]>0 && freq2[i]==0){
                return false;
            }
            else if(freq2[i]>0 && freq1[i]==0){
                return false;
            }
        }

        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());

        return freq1==freq2;

    }
};