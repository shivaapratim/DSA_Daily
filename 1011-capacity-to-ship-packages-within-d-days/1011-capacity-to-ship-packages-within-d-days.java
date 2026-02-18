class Solution {
     public int check(int[]weights, int mid, int days){
        int studentCnt=1;
        int pagesRead=0;
        for(int i=0; i<weights.length; i++){
            if(pagesRead+weights[i]>mid){
                studentCnt++;
                pagesRead=weights[i];
            }
            else{
                pagesRead+=weights[i];
            }

        }
        return studentCnt<=days ? 1 : 0;
    }

    public int shipWithinDays(int[] weights, int days) {
        int low = Arrays.stream(weights).max().getAsInt(); // maximum value 
        int high= Arrays.stream(weights).sum(); // sum of whole array
        int ans=low;

        while(low<=high){
            int mid= (low+high)/2;

            if(check(weights,mid,days)==1){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return ans;
    }

}