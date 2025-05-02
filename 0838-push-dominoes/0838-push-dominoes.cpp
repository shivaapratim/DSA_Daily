class Solution {
public:
    /*
        if L -> add L to res
        if . -> check while(!.) if ends at L-> put L if ends at R/end put all dots
        if R -> check next-> if L/R then add R if . then while(!.) if ends at R put R{
            careful
            if ends at L-> half side R from begin , half side L from end (if)-> odd= middle .
            ends at end-> put all R
        }
   */

    string pushDominoes(string dom) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        
        string res="";
        int n=dom.size();
        for(int i=0; i<n; i++){

            if(dom[i]=='L')res+='L';

            else if(dom[i]=='.'){
                int j=i; int cnt=0;
                while(j<n && dom[j]=='.'){
                    cnt++;
                    j++;
                }
                if(j<n && dom[j]=='L'){
                    for(int k=0; k<cnt; k++){
                        res+='L';
                    }
                }
                else{
                    for(int k=0; k<cnt; k++){
                        res+='.';
                        i=j;
                    }
                }
                i=j-1;
            }

            else if(dom[i]=='R'){

                res+='R';

                if (i + 1 < n && (dom[i + 1] == 'R' || dom[i + 1] == 'L')) {
                    // no further processing needed if the next char is not a dot
                }
                
                else{
                    int j=i+1; int cnt=0;
                    while(j<n && dom[j]=='.'){
                        cnt++;
                        j++;
                    }
                    if(j<n && dom[j]=='L'){
                        if(cnt%2==1){
                            for(int k=0; k<cnt/2; k++){
                                res+='R';
                            }
                            res+='.';
                            for (int k = 0; k < cnt / 2; k++) {
                                res += 'L';
                            }
                        }
                        else{
                            for(int k=0; k<cnt/2; k++){
                                res+='R';
                            }
                            for (int k = 0; k < cnt / 2; k++) {
                                res += 'L';
                            }
                        }
                    }
                    else{
                        for(int k=0; k<cnt; k++){
                            res+='R';
                        }
                    }
                    i = j - 1;
                }
            }
        }
        return res;
    }
};