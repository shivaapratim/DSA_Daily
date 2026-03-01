class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // [1,2] [1 3], [2,3] [3,4]

        int i=0; int j=1; int n= intervals.size(); int cnt=0;
        sort(intervals.begin(),intervals.end());

        while(j<n){

            int i_s=intervals[i][0];
            int i_e=intervals[i][1];

            int j_s=intervals[j][0];
            int j_e=intervals[j][1];
             

            if(i_e<=j_s){
                i=j;
                j++;
            }

            else if(i_e<j_e){
                cnt++;
                j++;
            }

            else if(i_e>=j_e){
                cnt++;
                i=j;
                j++;
            }
             
        }
        return cnt;
    }
};