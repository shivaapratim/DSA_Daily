class Solution {
public:

    int Swaps(int i,vector<int>&tops,vector<int>&bottoms){
        int swaps=0;
        for(int j=0; j<tops.size(); j++){
            
            if(tops[j]!=i && bottoms[j]!=i){
                return INT_MAX;
            }

            if(tops[j]!=i && bottoms[j]==i){
                swaps++;
            }
           
        }
        return swaps;
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int mini=INT_MAX;

        for(int i=1; i<=6; i++){

            mini= min({mini,Swaps(i,tops,bottoms),Swaps(i,bottoms,tops)});
        
        }

        return mini==INT_MAX ? -1 : mini;
    }
};