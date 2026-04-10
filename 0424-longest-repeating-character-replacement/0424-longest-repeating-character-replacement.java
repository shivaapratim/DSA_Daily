class Solution {
    public int characterReplacement(String s, int k) {
        int[] freq = new int[26];
        int head = -1;
        int tail = 0;
        int ans = 0;
        int n = s.length();
        int maxFreq = 0;

        while (tail < n) {

            // expand (check first, then move)
            while (head + 1 < n) {
                int idx = s.charAt(head + 1) - 'A';

                int newFreq = freq[idx] + 1;
                int newMaxFreq = Math.max(maxFreq, newFreq);
                int window = (head + 1) - tail + 1;

                if (window - newMaxFreq <= k) {
                    head++;
                    freq[idx]++;
                    maxFreq = newMaxFreq;
                } else {
                    break;
                }
            }

            ans = Math.max(ans, head - tail + 1);

            // shrink (same as your template)
            if (tail <= head) {
                freq[s.charAt(tail) - 'A']--;
                tail++;
            } else {
                tail++;
                head = tail - 1;
            }
        }

        return ans;
    }
}