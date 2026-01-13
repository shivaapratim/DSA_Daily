class Solution {
public:

    int acc(int i, int j, vector<int>&n){
        int sum=0;
        while(i<=j){
            sum+=n[i];
            i++;
        }
        return sum;
    }

    bool isEqual(int i, int j, int sum, vector<int>&n){
        while(i<=j){
            if(sum==n[i])return true;
            i++;
        }
        return false;
    }

    int centeredSubarrays(vector<int>& nums) {

        int ans=0;

        for(int i=0; i<nums.size();i++){
            for(int j=i; j<nums.size();j++){
                int total = acc(i,j,nums);
                bool check= isEqual(i,j,total,nums);
                if(check)ans++;
            }
        }

        return ans;
    }
};