class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int avg = 0;
        int sum = 0;
        map<int,int> mp;
        int n = nums.size();
        for(auto el: nums){
            sum+=el;
            mp[el]++;
        }

        avg = sum/n;
        for(int i = max(1, avg+1); i<200; i++){
            if(!mp.count(i)){
                return i;
            }
        }
        return -1;
    }
};