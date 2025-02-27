class Solution {
public:

    int solve(int i, vector<int>&arr,int p1, int p2, int len){
        if(i>=arr.size()){
            return len>=3 ? len:0;
        }
        int nonpick= solve(i+1,arr,p1,p2,len);

        int pick=0;

        if(len<2){
            pick=solve(i+1,arr,p2,arr[i],len+1);
        }
        else if(arr[i]==p1+p2){
            pick = solve(i + 1, arr, p2, arr[i], len + 1);
        }
        
        return max(pick,nonpick);
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        // string s="";
        return solve(0,arr,-1,-1,0);
    }
};