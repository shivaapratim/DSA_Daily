
class Solution {
    public int totalFruit(int[] fruits) {

        int n = fruits.length;

        int tail = 0, head = -1;
        HashMap<Integer, Integer> map = new HashMap<>();
        int distinctCount = 0, ans = 0;

        while (tail < n) {

            // expand
            while (head + 1 < n && (map.containsKey(fruits[head + 1]) || distinctCount < 2)) {
                head++;

                map.put(fruits[head], map.getOrDefault(fruits[head], 0) + 1);

                if (map.get(fruits[head]) == 1)
                    distinctCount++;
            }

            ans = Math.max(ans, head - tail + 1);

            // shrink
            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                map.put(fruits[tail], map.get(fruits[tail]) - 1);

                if (map.get(fruits[tail]) == 0) {
                    map.remove(fruits[tail]);
                    distinctCount--;
                }

                tail++;
            }
        }

        return ans;
    }
}