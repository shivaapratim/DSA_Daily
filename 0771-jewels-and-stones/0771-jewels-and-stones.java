class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        int i=0; 
        int n=jewels.length();
        int m=stones.length();
        int cnt=0;

        while(i<n){
            int j=0;
            while(j<m){
                if(jewels.charAt(i)==stones.charAt(j)){
                    cnt++;
                } 
                j++;
            }
            i++;
        }

        return cnt;
    }
}