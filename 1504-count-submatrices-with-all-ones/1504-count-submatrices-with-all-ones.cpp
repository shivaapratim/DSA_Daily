class Solution {
public:


    // void NextGreaterToLeft(vector<int>&nslLength, vector<int>&hist){

    //     stack<int>st;

    //     for(int i=0; i<hist.size(); i++){
    //         int length=1;

    //         while(!st.empty() && st.top()>hist[i]){
    //             st.pop();
    //             length++;
    //         }

    //         st.push(hist[i]);

    //         nsrLength[i]=length;
    //     }

    // }
    // void NextGreaterToRight(vector<int>&nsrLength, vector<int>&hist){

    //     stack<int>st;

    //     for(int i=hist.size()-1; i>=0; i--){
    //         int length=1;

    //         while(!st.empty() && st.top()>hist[i]){
    //             st.pop();
    //             length++;
    //         }

    //         st.push(hist[i]);

    //         nsrLength[i]=length;
    //     }

    // }


    int areaOfHistogram(vector<int>&hist){

        int ans = 0;
        for(int i = 0; i < hist.size(); i++){

            int minHeight = hist[i];

            //[0,1,1,0] -> [1] , [1], [1,1]

            //All possible rectangles ending at i
            

            for(int j = i; j<hist.size(); j++){  
                minHeight = min(minHeight, hist[j]);
                ans += minHeight;
            }

        }
        return ans;
    }


    int numSubmat(vector<vector<int>>& mat) {
        
        vector<int>hist(mat[0].size(),0);

        int ans=0;

        for(int i=0; i<mat.size(); i++){
            
            for(int j=0; j<mat[0].size(); j++){

                if(mat[i][j]==0){
                    hist[j]=0;
                }

                else{
                    hist[j]+=mat[i][j];
                }

            }

            ans+=areaOfHistogram(hist);

        }

        return ans;

    }
};