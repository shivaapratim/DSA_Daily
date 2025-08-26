class Solution {
public:
    
    int sqr(int length){
        return length * length;
    }

    int area(int l, int b){
        return l * b;
    }

    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        
        int maxi = 0;
        double diaMax = 0;    

        for(int i = 0; i < dim.size(); i++){
            int l = dim[i][0];
            int b = dim[i][1];

            double dia = sqrt(sqr(l) + sqr(b));    

            if(dia > diaMax || (dia == diaMax && area(l, b) > area(dim[maxi][0], dim[maxi][1]))){
                diaMax = dia;   // ✅ update
                maxi = i;
            }
        }

        return area(dim[maxi][0], dim[maxi][1]);
    }
};
