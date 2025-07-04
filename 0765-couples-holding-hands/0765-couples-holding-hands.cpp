class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        map<int,int>mpp;
        int n=row.size();
        for(int i=0;i<n;i++){
            mpp[row[i]]=i;
        }
        int ans=0;
        for(int i=0;i<n;i+=2){
            if(row[i]%2==0){
                if(mpp[row[i]+1]==i+1){
                    continue;
                }
                else{
                    ans++;
                    int temp=mpp[row[i]+1];
                    mpp[row[i+1]]=temp;
                    mpp[row[i]+1]=i+1;
                    swap(row[i+1],row[temp]);
                }
            }
            else{
                if(mpp[row[i]-1]==i+1){
                    continue;
                }
                else{
                    ans++;
                    int temp=mpp[row[i]-1];
                    mpp[row[i+1]]=mpp[row[i]-1];
                    mpp[row[i]-1]=i+1;
                    swap(row[i+1],row[temp]);
                }
            }
        }
        return ans;
    }
};