class Solution {
public:
    string minWindow(string s, string t) {

        //Approach goood

        //Just use decrementation and incrementation in values of t and s

        //Use 0 as the best case if less than 0 try to shrink i++...j
        //If >0 in hash then make the string large enough to store all ouccred elements
        
        vector<int>hash(128,0);
        int m=s.length();
        int n=t.length();
        for(int i=0; i<n; i++){
            hash[t[i]]++;
        }
        int i=0,j=0;
        int cnt=n, start=0;
        int minlength=INT_MAX;

        while(j<m){
            if(hash[s[j]]>0)cnt=cnt-1;
            hash[s[j]]--;
            j++;
            while(cnt==0){
                if(j-i<minlength){
                    minlength=j-i;
                    start=i;
                }
                hash[s[i]]++;
                if(hash[s[i]]>0){
                    cnt++;
                }
                i++;
            }
        }
        return minlength == INT_MAX ? "" : s.substr(start, minlength);
    }
};