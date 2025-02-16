class Solution {
public:
    //Lallu solution u tried

    // bool isvalid(int j,vector<int>&arr){
    //     if(arr[arr.size()-j]==j){
    //         return true;
    //     }
    //     return false;
    // }

    // void solve(int i, int n, bool one, vector<vector<int>>&ans, vector<int>&arr){
    //     if(i>n*2-1){
    //         ans.push_back(arr);
    //         return;
    //     }

    //     for(int j=i; j<=n; j++){
    //         if(isvalid(j,arr)){
    //             ans.push_back(j);
    //             solve(j+1,arr,ans);
    //         }
    //         else if(one){
    //             ans.push_back(1);
    //             one=false;
    //             solve(j,arr,ans);
    //         }
    //     }
    // }


    bool solve(int i, int n, vector<int>&result, vector<bool>&used){

        if(i>=result.size()){
            return true; //-> this means answer cause we started to fill from big to small
        }

        if(result[i]!=-1){
            //Some number is already here
            return solve(i+1,n,result,used);
        }

        for(int num=n; num>=1; num--){
            if(used[num]){
                continue;
            }
            used[num]=true;
            result[i]=num;

            if(num==1){
                if(solve(i+1,n,result,used)==true){
                    return true;
                }
            }
            else{
                int j= result[i]+i;

                if(j<result.size()&&result[j]==-1){
                    result[j]=num;
                    if(solve(i+1,n,result,used)==true){
                        return true;
                    }
                    result[j]=-1;
                }     
            }
            //undo

            used[num]=false;
            result[i]=-1;
            
        }
        return false;
    }


    vector<int> constructDistancedSequence(int n) {
        vector<int>result(2*n-1,-1);
        vector<bool>used(n+1,false);

        solve(0,n,result,used);
        return result; 
    }
};