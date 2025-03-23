class Solution {
public:
    int trap(vector<int>& height) {

        int n= height.size();
        vector<int> maxl(n, 0), maxr(n, 0);
        
        int maxi=0;
           
        for(int i=0; i<height.size(); i++){
            maxi=max(height[i],maxi);
            maxl[i]=(maxi);

        }  
        maxi=0;
        for(int i=height.size()-1; i>=0; i--){
            maxi=max(height[i],maxi);
            maxr[i]=(maxi);
        }  
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            sum += min(maxr[i], maxl[i]) - height[i];
        }
        return sum;


    }
};