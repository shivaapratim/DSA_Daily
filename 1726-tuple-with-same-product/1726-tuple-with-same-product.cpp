class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int tup=0;

        for(auto it: mp){
            if(it.second>=2){
                int t= it.second*(it.second-1)/2;
                tup+=t*8;
            }
        }
        return tup;
    }
};