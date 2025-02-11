class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0;
        int i=0;

        // [a,a,a,a,a,a,a,a,a,a,,b,b]

        //[a,1,0,b,2]

        //return 5 then only till 5 it will check.

        while(i<chars.size()){
            // Yahi dimag me laao ki loop ke andar check kar sakte doosra loop laga ke
            // Taking a value in start out of the loop isn't really necessary.
            char curr=chars[i];
            int cnt=0;

            //jb tak same hai tab tak aage badho
            while(i<chars.size() && chars[i]==curr){
                cnt++;
                i++;
            }

            //Now assign work

            chars[idx]=curr;// Start pe jo hai usme value daal do ,technically repeat hi hogi
            // a  a  a  a  a  b
            //idx             i    idx=a

            idx++;
            //Ab count ko assign kar do
            string g= to_string(cnt);

            if(cnt>1){ // Maan lo agar string hai {a,b} toh ise ab likhenge naki a1b1

                for(int j=0; j<g.length();j++){
                    chars[idx]=g[j];
                    idx++;
                }

            }

        }
        return idx;
    }
};