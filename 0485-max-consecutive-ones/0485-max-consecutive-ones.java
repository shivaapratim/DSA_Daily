class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int n=nums.length;
        int head = -1; // Explain ?
        int tail = 0;
        int ans = 0;
        int cnt0 = 0;
        int k=0;

        while (tail < n) {
            while (head + 1 < n && (cnt0 + (1 - nums[head + 1]) <= k)) { // check
                head++;
                if (nums[head] == 0)
                    cnt0++;
            }
            ans = Math.max(ans, head - tail + 1);

            if (tail <= head) {
                if (nums[tail] == 0) {
                    cnt0--;
                }
                tail++;
            } else if (tail > head) {
                tail++;
                head = tail - 1; // ?????????
            }

        }

        return ans;
    }
}