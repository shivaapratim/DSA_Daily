class Solution {
public:
    int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        //What im thinking for this problem is as we have to come to each element at least once
        //Then a constructive way to compute the running sum is very important, and this is the
        //Only scope for making our code efficient by taking the running sum and adding next ones

        //Now as this problem is not a subsequence problem we therefore have not to skip any part
        //That means we have to iterate through each j after i and by this i can also think of using stack
        //Cause when j depends on i then stack is helpful..Maybe a slight hint towards recursion

        //The face about the running sum as i can see is either we have to add next j to the running sum
        //Or just dont add and make a new call for others from that j as starting sum.

        //And we can also compute the running sum at each call..So all of this gives me a hint of using 
        //Recursion and DP 


        //Par yahan prefix and odd even ki count se banega cuz-> even+odd=odd

        int even=1;
        int odd=0;
        int ans=0;
        int sum=0;

        for(int i=0; i<arr.size(); i++){

            sum+=arr[i];

            if(sum%2==0){
                (ans+=odd)%MOD;
                even++;
            }
            else if(sum%2==1){
                (ans+=even)%MOD;
                odd++;
            }

        }
        return ans;
    }
};