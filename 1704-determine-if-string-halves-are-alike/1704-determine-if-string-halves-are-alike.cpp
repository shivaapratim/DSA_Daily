class Solution {
public:
    bool halvesAreAlike(string s) {
        int n= s.length();
        int i=0; int j=n/2;
        int cnti=0,cntj=0;
        set<char>st={'a','e','i','o','u'};

        while(i<n/2 && j<n){
            if(st.find(tolower(s[i]))!=st.end()){
                cnti++;
            }
            if(st.find(tolower(s[j]))!=st.end()){
                cntj++;
            }
            i++;
            j++;
        }
        return cnti==cntj;
    }
};