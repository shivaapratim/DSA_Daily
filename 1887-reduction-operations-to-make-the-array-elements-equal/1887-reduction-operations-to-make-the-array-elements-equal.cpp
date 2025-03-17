class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        if(nums.size()==1)return 0;

        map<int,int>mp; //For sorted order

        for(auto&it: nums){
            mp[it]++;
        }

        //Here we just have to take extra one variable as mincount, which will tell
        //How many times we have to change the number
        int ans=0, mini=mp.begin()->first, mincnt=0;

        for(auto &it: mp){
            if(it.first==mini)continue;
            else{
                ans+=mincnt+it.second;
                mincnt++;
                mini=it.first;
            } 
        }
        return ans;
    }
};