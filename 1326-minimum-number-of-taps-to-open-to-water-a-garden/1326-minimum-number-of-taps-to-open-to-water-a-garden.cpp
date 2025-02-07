class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int taps=0;
        vector<int>startEnd(n+1,0);

        // main problem is to where will the taps be opened for the best case.

        // For this we have taken another variable curr, which will tell from a specific
        //Index it where we can go and when it exhausts we open the tap


        int s=0;int e=0;
        for(int i=0; i<ranges.size();i++){
            //Precompute the length of left and right side.
            s=max(i-ranges[i],0);
            e=min(i+ranges[i],n);

            startEnd[s]= max(startEnd[s],e);
        }

        int maxEnd=0;
        int curr=0;

        for(int i=0; i<ranges.size(); i++){
            
            if(i>maxEnd){
                return -1;
            }
            if(i>curr){
                taps++;
                curr=maxEnd;
            }
            maxEnd= max(maxEnd,startEnd[i]);

        }

        return taps;
    }
};