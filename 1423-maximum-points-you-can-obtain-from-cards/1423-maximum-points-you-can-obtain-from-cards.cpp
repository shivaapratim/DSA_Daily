class Solution {
public:
    int maxScore(vector<int>& cardPoint, int k) {
        // Ek 0-> k tak hi utha sakte 
        //Toh pehle 0 -> k sum kar lo then as we know ki ya toh peeche se ek hatega ya aage se
        //So just check 0->k for all and n->n for all k->0
        //Samjh nahi aaya hoga, umm [2,1,3,4,5] try from 2,1,3,4 this gives some sum
        //Now try removing 4 and check 2,1,3,5 one from back, then 2,1,4,5 whichever gives the largest
        //sum is the answer

        int sum=0;
       for(int i=0; i<k; i++){
        sum+=cardPoint[i];
       }
        int temp=k-1;
        int maxi=sum;
        int n=cardPoint.size();
        int i=1;
        while(temp>=0){
           maxi-=cardPoint[temp];
           maxi+=cardPoint[n-i];
           i++;
           temp--;
           sum=max(sum,maxi);
        }
        return sum;

    }
};