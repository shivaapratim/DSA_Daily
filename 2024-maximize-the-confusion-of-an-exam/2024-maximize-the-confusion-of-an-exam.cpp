class Solution {
public:

    int solve(char check, string answerKey, int k){
        int h=-1;
        int t=0;
        int ans=0;
        int cnt=0;
        
        while(t<answerKey.length()){
            while(h+1<answerKey.length() && (cnt+ (answerKey[h+1]==check ? 1 : 0)<=k)){
                h++;
                cnt += (answerKey[h]==check ? 1 : 0);
            }
            ans= max(ans,h-t+1);

            if(t<=h){
                if(answerKey[t]==check){
                    cnt--;
                }
                t++;
            }
            else{
                t++;
                h=t-1;
            }
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve('T',answerKey,k),solve('F',answerKey,k));
    }
};