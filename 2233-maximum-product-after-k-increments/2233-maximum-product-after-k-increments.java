
import java.util.PriorityQueue;

class Solution {
    public int maximumProduct(int[] nums, int k) {
        final int MOD = 1_000_000_007;

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int num : nums) {
            pq.offer(num);
        }

        while (k > 0) {
            int smallest = pq.poll();
            pq.offer(smallest + 1);
            k--;
        }

        long ans = 1;

        while (!pq.isEmpty()) {
            ans = (ans * pq.poll()) % MOD;
        }

        return (int) ans;
    }
}
