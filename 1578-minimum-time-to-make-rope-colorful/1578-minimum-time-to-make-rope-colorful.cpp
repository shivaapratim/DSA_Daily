class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        //two pointer is possible in a way if we encounter the same character then
        //from that character we can simply calculate the totalsum of all neededtime-maxelement

        int n=colors.length();  int mini=0; int m=neededTime.size();

        for(int i=0; i<n-1; i++){
            if(colors[i]==colors[i+1]){
                int maxcnt = 0 ;
                int maxval=INT_MIN;
                while(i<n-1 && colors[i]==colors[i+1]){
                    maxcnt+=neededTime[i];
                    maxval=max(maxval,neededTime[i]);
                    i++;
                }
                maxcnt+=neededTime[i];
                maxval=max(maxval,neededTime[i]);

                mini+=maxcnt-maxval;
            }
        }
        return mini;
    }
};