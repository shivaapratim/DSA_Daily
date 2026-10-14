import java.util.HashMap;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (mp.containsKey(nums[i])) {
                mp.put(nums[i], mp.get(nums[i]) + 1);
            } else {
                mp.put(nums[i], 1);
            }
        }

        for (int count : mp.values()) {
            if (count >= 2) {
                return true;
            }
        }

        return false;
    }
}