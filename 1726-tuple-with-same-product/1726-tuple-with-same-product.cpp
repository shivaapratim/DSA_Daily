class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // using concept of if we know 3 we can know the other 1
        // O(n^3)
        sort(nums.begin(),nums.end());
        int tup=0;
        int n=nums.size();
        for(int i=0; i<n;i++){
            for(int j=n-1; j>i; j--){
                // set to store the value of product 
                unordered_set<int>st;
                int product= nums[i]*nums[j];
                for(int k=i+1; k<j; k++){

                    if(product%nums[k]==0){
                        int want=product/nums[k];
                        if(st.count(want)){
                            tup++;
                        }
                        st.insert(nums[k]);
                    }
                    
                }
            }
        }
        return tup*8;
    }
};