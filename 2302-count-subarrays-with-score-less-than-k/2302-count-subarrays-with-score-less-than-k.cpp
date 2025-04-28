class Solution {
public:
    //Total summ
    //Minimize total sum when i++
    //New subarray afeter i++ will be new array, cause usse pehle saare count kar chuke honge
    //i++ leke
    //Pre compute-> TotalSum and length
    //new lengths should be alinged with the algo of n,j,i some arithmetic concpt
    
    typedef long long ll;

    long long countSubarrays(vector<int>& nums, long long k) {
        
        ll n =nums.size();
        ll tempsum=0;
        ll templen=0;
        ll i=0,j=0;
        ll cnt=0;

        while(j<n){
            tempsum+=nums[j];
            templen++;

            while(i<=j && (tempsum*templen) >= k){
                templen--;
                tempsum-=nums[i];
                i++;
            }
            cnt+=(j-i+1);

            j++;
        }

        return cnt;

    }
};