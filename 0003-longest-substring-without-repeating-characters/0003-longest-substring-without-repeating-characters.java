class Solution {
    public int lengthOfLongestSubstring(String s) {

        int[] freq = new int[256];
        int head = -1;
        int tail = 0;
        int ans = 0;
        int n = s.length();

        while (tail < n) {

            while (head + 1 < n && freq[s.charAt(head + 1)] == 0) {
                head++;
                freq[s.charAt(head)]++;
            }

            ans = Math.max(ans, head - tail + 1);

            if (tail <= head) {
                freq[s.charAt(tail)]--;
                tail++;
            } else {
                tail++;
                head = tail - 1;
            }
        }

        return ans;
    }
}