class Solution {
    public int largestAltitude(int[] gain) {
        int n=gain.length;
        int arr[] = new int[n+1];

        int maxi=0;

        for(int i=0; i<=n; i++){
            if(i==0){
                arr[i]=0;
            }
            else{
                arr[i]=gain[i-1]+arr[i-1];
                maxi=Math.max(maxi,arr[i]);
            }
        }

        return maxi;
    }
}