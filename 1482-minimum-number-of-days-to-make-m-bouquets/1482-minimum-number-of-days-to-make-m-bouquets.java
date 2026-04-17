class Solution {

    public int check(int mid, int[] bloomDay, int m, int k){
        int flowers = 0;
        int bouquets = 0;

        for(int i = 0; i < bloomDay.length; i++){
            if(bloomDay[i] <= mid){
                flowers++;
                if(flowers == k){
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        return bouquets >= m ? 1 : 0;   // FIRST TRUE (valid)
    }

    public int minDays(int[] bloomDay, int m, int k) {
         

        int low = 1;
        int high = 0;

        for(int x : bloomDay) high = Math.max(high, x);

        int ans = -1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(check(mid, bloomDay, m, k) == 1){
                ans = mid;
                high = mid - 1;   // move LEFT (first valid)
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
}