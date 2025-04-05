class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        //This question has it's j'th  loop dependent upon i
        //So we can think of stack as a solution.
        //How can stack be helpful in generating all the subsets?

        //Seekh-> har baar bhi stack nahi sochna hota hai, jab tumhe optimality di gyi ho
        //tab socho stack, like min/max from each subarray, tab vahan NSR, NSL ye sab sochna.

        //XOR ki property enough hai is question ke liye.

        int n=nums.size();
        int result=0;

        for(auto&nu:nums){
            result|=nu;
        }
        return result<<(n-1);
    }
};