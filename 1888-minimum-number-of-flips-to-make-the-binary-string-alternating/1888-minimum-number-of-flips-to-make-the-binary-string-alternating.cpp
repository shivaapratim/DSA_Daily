class Solution {
public:
    int minFlips(string s) {
        // One way i can think is just check for if the last and first are not equal
        // Then take the first and put it in the back
        // Or if they are equal, then flip the front's bit and send it to back while
        // Counting the number of flips.
        // Repeat it till length of the array times and we can get the answer.

        //For ex:
        /*
            1110, so front(1) and last(0) are not equal so just append 1 to last and remove from
            front we get 1010 till here we have gotten our answer but just for surety we check the same
            for 3 times more

        Another ex:
            111000, so applying same logic first it will be 
            -> 110001
            -> 1,1 are same so flip and send to back
            -> 1000010 -> 0000101 -> 0001010 -> same so flip and send back -> 0010101
            -> 0101010 minflip = 2;
        */

        // But this fails for -> 0110

        //So we know that possible alternative ways are-> 101010 or 010101 etc..depends on the size

        //So we just have to find the minimum of possible ways->
        //Meaning-> 
        // 111000-> min(diff(111000 to 101010 or 010101), for all type 1 case, which will make it O(N^2)
        //Sliding window with two pointer here comes to help, as we just have to check the start and last
        //In each iteration.
 
        int n = s.size();
        // To simulate rotation, double the string.
        string s2 = s + s;
        
        // Build two alternating patterns (of length 2*n) for comparison.
        // alt1: "0101..." and alt2: "1010..."
        string alt1, alt2;
         
        for (int i = 0; i < 2 * n; i++) {
            if (i % 2 == 0) {
                // For even index assign '0' for alt1 and '1' for alt2.
                alt1.push_back('0');
                alt2.push_back('1');
            } else {
                alt1.push_back('1');
                alt2.push_back('0');
            }
        }
        
        int res = INT_MAX;
        int diff1 = 0; // mismatch counter for alt1
        int diff2 = 0; // mismatch counter for alt2
        
        // Sliding window over s2 of length n:
        for (int i = 0; i < 2 * n; i++) {
            // Update mismatch counters as we extend the window.
            if (s2[i] != alt1[i]) diff1++;
            if (s2[i] != alt2[i]) diff2++;
            
            // When window size exceeds n, slide by removing the i-n-th character's effect.
            if (i >= n) {
                if (s2[i - n] != alt1[i - n]) diff1--;
                if (s2[i - n] != alt2[i - n]) diff2--;
            }
            
            // Once window size equals n, check the minimum flips needed.
            if (i >= n - 1) {
                res = min(res, min(diff1, diff2));
            }
        }
        
        return res;
    }
 

};