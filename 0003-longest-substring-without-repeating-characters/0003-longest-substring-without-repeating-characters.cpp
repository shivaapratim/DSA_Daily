class Solution {
public:
    unordered_map<char,int>ch;
    
    int check(char word){
        return ch.find(word)==ch.end();
    }

    int lengthOfLongestSubstring(string s) {
        

        int head=-1;
        int tail=0;
        int ans=0;
        int n=s.length();

        while(tail<n){
            while(head+1<n && check(s[head+1])){
                head++;
                ch[s[head]]++;
            }
            ans=max(ans, head-tail+1);

            if(tail<=head){
                ch[s[tail]]--;
                if(ch[s[tail]]==0){
                    ch.erase(s[tail]);
                }
                tail++;
            }
            else{
                tail++;
                head=tail-1;
            }
        }
        return ans;

    }
};