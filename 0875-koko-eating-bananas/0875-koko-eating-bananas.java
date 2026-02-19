class Solution {

    public int check(int[] piles, int mid, int h) {
        long totalCount = 0;
        for (int i = 0; i < piles.length; i++) {
            totalCount += (piles[i] + mid - 1) / mid;    
        }
        return totalCount<=h ? 1 : 0;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = Arrays.stream(piles).max().getAsInt();
        int ans= 1;
 
        while (low <= high) {
            int mid = (low+high)/2;

            if (check(piles, mid,h)==1) {
                ans=mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
}
