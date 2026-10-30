class Solution {
    public long maximizeSum(int[] nums, int k) {

        int n = nums.length;
        int[] gains = new int[n];

        long sum = 0;

        for (int i = 0; i < n; i++) {

            sum += nums[i];

            char[] arr = String.valueOf(nums[i]).toCharArray();

            Arrays.sort(arr);

            int max = 0;

            for (int j = arr.length - 1; j >= 0; j--) {
                max = max * 10 + (arr[j] - '0');
            }

            gains[i] = max - nums[i];
        }

        Arrays.sort(gains);

        for (int i = n - 1; i >= 0 && k > 0; i--) {
            sum += gains[i];
            k--;
        }

        return sum;

    }
}