class Solution {
    public int findClosest(int x, int y, int z) {
        int absX= Math.abs(z-x);
        int absY= Math.abs(z-y);
        if(absX<absY)return 1;
        else if(absX>absY)return 2;
        return 0;
    }
}