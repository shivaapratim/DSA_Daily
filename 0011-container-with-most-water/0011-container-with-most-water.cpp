class Solution {
public:
    int maxArea(vector<int>& nums) {
        int maxi=0;

        // for(int i=0; i<nums.size();i++){
        //     for(int j=i+1; j<nums.size();j++){
        //         int mini=min(nums[i],nums[j]);
        //         int area= mini*(j-i);
        //         maxi=max(area,maxi);
        //     }
        // }

        int s=0,e=nums.size()-1;

        while(s<e){
            int mini=min(nums[s],nums[e]);
            int area= mini*(e-s);
            maxi=max(area,maxi);
            if(nums[s]<nums[e])s++;
            else if(nums[s]>nums[e])e--;
            else s++; //or e--
        }

        return maxi;
    }
};