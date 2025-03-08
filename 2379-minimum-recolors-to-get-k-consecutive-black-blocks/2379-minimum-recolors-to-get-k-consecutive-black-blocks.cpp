class Solution{
public:

    int minimumRecolors(string blocks, int k) {
        // Count the number of whites in window k, minimum will be the answer.
        int whiteCount = 0;
        int i = 0;
        while (i < k) {
            if (blocks[i] == 'W') whiteCount++;
            i++;
        }
        
        int minWhite = whiteCount;
        
        
        while (i < blocks.size()) {
            
            if (blocks[i - k] == 'W') whiteCount--;
        
            if (blocks[i] == 'W') whiteCount++;
            
            minWhite = min(minWhite, whiteCount);
            i++;
        }
        
        return minWhite;
    }
};

