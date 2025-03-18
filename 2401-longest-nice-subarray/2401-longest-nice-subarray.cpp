class Solution {
public:

    //Sliding window me XOR krke hta skte hain

    int longestNiceSubarray(vector<int>& nums) {
        
        if(nums.size()==1)return 1;

        int l=0,r=0,maxlen=0;
        int mask=0;

        while(r<nums.size()){
            if((nums[r] & mask) == 0){
                mask |= nums[r];
                maxlen=max(maxlen,r-l+1);
                r++;
            }
            else if((nums[r] & mask) !=0){
                mask ^= nums[l];
                l++;
            }

        }
        return maxlen;
    }
};