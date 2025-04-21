class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        int minval=0;
        int maxval=0;
        int curr=0;// lets take 0 at start hidden
        
        //pehle 0 se start kar do kyunki ek baar df nikal gya toh alpha(x) value se shift kar
        //skte taake bounds mein aa jaaye.

        //Itna pata hai ki ek alpha value se shift karne se difference pe frk nahi padega
        //poori array mein 

        for(int i=0; i<d.size(); i++){
            curr+=d[i];
            
            minval= min(curr,minval);
            maxval= max(curr,maxval);

            //alpha R=[L-minval,U-maxval] -> hidden sequence 
            
            //b-a+1 -> total sequence, a= L-minval, b= U-maxval

            if((upper-maxval) - (lower-minval) +1 <=0){
                return 0; //invalid;
            }
        }

        return (upper-maxval) - (lower-minval)+1;
    }
};