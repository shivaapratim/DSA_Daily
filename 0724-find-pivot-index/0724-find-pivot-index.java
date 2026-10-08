class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;

        int[] left = new int[n];
        int[] right = new int[n];

        // left[i] = left[i-1] + nums[i]
        for (int i = 0; i < n; i++) {
            if (i == 0)
                left[i] = 0;
            else
                left[i] = left[i - 1] + nums[i-1];
        }


        // right[i] = right[i+1] + nums[i]
        for (int i = n-1; i >=0; i--) {
            if (i == n-1)
                right[i] = 0;
            else
                right[i] = right[i + 1] + nums[i+1];
        }

        for (int i = 0; i < n; i++) {
            if (left[i] == right[i]) {
                return i;
            }
        }

        return -1;
    }
}