class Solution {
public:

    bool convertToBin(string st, int k) {
    long long num = 0;
    for (char bit : st) {
        num = (num << 1) + (bit - '0');
        if (num > k) {
            return false;
        }
    }
    return true;
}
    int longestSubsequence(string s, int k) {
         
        string st;

        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='0'){
                st.insert(st.begin(),'0');
            }
            else{
                string temp=st;
                temp.insert(temp.begin(),'1');
                if(convertToBin(temp,k)){
                    st=temp;
                }
            }
        }
        return st.size();
    }
};