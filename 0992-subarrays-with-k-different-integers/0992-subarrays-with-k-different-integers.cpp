class Solution {
public:
    // WERE there bas thoda sa chook gye calculation mein

    //Approach- suppose i have 3 distinct arrays
    //[1,2,1,2] k=1 -> 1st iteration 1 finds 2 at 1st position then j= 3- (2's position)= 3-1=2
    //and +1 cause 1,2 is also valid. 1 gets removed from map Second iteration 2 finds 1 at position 2
    // j-1's position= 3-2=1 and +1 for 2,1 . Third iteration 1 finds 2 at j so 0 but 1,2 so +1
    //Overall answer= 3+2+1= 6. and i is now at j.

    //[1,2,2,1] k=2 -> 1st iteration 1 finds 2 at 1st position then j= 3- (2's position)= 3-1=2
    //and +1 cause 1,2 is also valid. 1 gets removed from map Second iteration 2 finds 1 at position 3(j)
    // j-1's position= 3-3=0 but +1 for 2,2,1 . Third iteration 2 finds 1 at j so 0 but 2,1 so +1
    //Overall answer= 3+2+1= 5. and i is now at j.

    //Irrespective of there sizes, I get df output for both because it is needed to check
    //If the inside elements can make a k subarray and once found then from that point i can say
    //Next all subarrays are possible

    // unordered_map<int,int>mp;
    // long long ans;

    // void solve(int&i, int j, int k, vector<int>&nums){
        
    //     while( (i<=j) && (j-i>=k)){ 

    //         set<int>st;
    //         int s=i;
    //         for(; s<=j; s++){
                
    //             st.insert(nums[s]);
    //             if(st.size()==k){
    //                 break;
    //             }

    //         }
    //         ans+= ((j-s) +1);  // j-s= number found at s for valid k distincts, +1 for currennt to before subarray
            
    //         if(mp[nums[i]]==1)
    //         mp.erase(nums[i]);
            
    //         else mp[nums[i]]--;

    //         i++;

    //     }

    // }


    // int subarraysWithKDistinct(vector<int>& nums, int k) {
        
    //     int i=0;
    //     int j=0;
    //     ans=0;
    //     int n=nums.size();

    //     while(j<n){
    //         mp[nums[j]]++;
    //         if(mp.size()>k){
    //             if(--mp[nums[j]]==0)
    //             mp.erase(nums[j]);

    //             solve(i,j-1,k,nums);
    //         }
    //         j++;
    //     }

    //     solve(i,n-1,k,nums);
        

    //     return ans;

    // }


    int subarraysWithKDistinct(vector<int>& nums, int k){
        
        int n=nums.size();

        unordered_map<int,int>mp;

        int i= 0;
        int j=0; 
        int i_=0;

        int ans=0;

        while(j<n){
            mp[nums[j]]++;

            while(mp.size()>k){
                mp[nums[i]]--;

                if(mp[nums[i]]==0)mp.erase(nums[i]);

                i++;

                i_=i;
            }

            while(mp[nums[i]]>1){
                mp[nums[i]]--;

                i++;
            }

            if(mp.size()==k){
                ans+= (1+ i - i_);
            }

            j++;
        }


        return ans;

    }   


};