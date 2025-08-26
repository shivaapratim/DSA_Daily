class Solution {
public:
    
    int sqr(int length){
        return length*length;
    }

    int area(int l, int b){
        return l*b;
    }

    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        
        int maxi= 0;
        int diaMax=0;

        for(int i=0; i<dim.size();i++){
            int l= dim[i][0];
            int b= dim[i][1];

            int sqrL = sqr(l);
            int sqrB = sqr(b);

            int dia = (sqrL)+(sqrB);

            if(dia>diaMax){
                maxi= i;
                diaMax=dia;
            }
            
        }

        return area(dim[maxi][0], dim[maxi][1]);
    }
};