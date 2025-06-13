class Solution {
public:
    //Pick not pick in a way that either of the matchstick contributes to same side or
    //THe other side
    //Once the square is formed return true


    //Square formation-> At the start check the sum if it is not divisible by 4 it means swaure cannot be formed
    //Secondly if it is sum/4 = length of each side. That means we can use a target variable and check for the 4 sides
    //in arr if it can be made equal to target.
    int n,target;
    
    bool solve(int i, vector<int>&arr, vector<int>&match){
        if(i>=n){
            if(arr[0]==target && arr[1]==target && arr[2]==target && arr[3]==target){
                return true;
            }
        
            return false;
        } 

        for(int j=0; j<4; j++){
            if(arr[j]+match[i]>target)continue;
            arr[j]+=match[i];
            if(solve(i+1,arr,match))return true;
            arr[j]-=match[i];   
            if (arr[j] == 0)
                break; 
        }

        return false;
    }
     
    bool makesquare(vector<int>& match) {
        n= match.size();
        long long sum=accumulate(match.begin(),match.end(),0LL);
        if(sum%4!=0)return false;

        target= sum/4;

        vector<int>arr(4,0);
        sort(arr.begin(),arr.end(),greater<int>());//Optimization for fast checking(pruning) 
        //if(arr[j]+match[whatever index] > target) means false. 
        if (match[0] > target) 
            return false;
        
        return solve(0,arr,match);
    }
};