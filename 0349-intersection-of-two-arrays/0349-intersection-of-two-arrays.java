

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {

        List<Integer> arr = new ArrayList<>();

        HashMap<Integer, Integer> mp1 = new HashMap<>();
        HashMap<Integer, Integer> mp2 = new HashMap<>();

        for (int i = 0; i < nums1.length; i++) {
            if (mp1.containsKey(nums1[i])) {
                mp1.put(nums1[i], mp1.get(nums1[i]) + 1);
            } else {
                mp1.put(nums1[i], 1);
            }
        }

        for (int i = 0; i < nums2.length; i++) {
            if (mp2.containsKey(nums2[i])) {
                mp2.put(nums2[i], mp2.get(nums2[i]) + 1);
            } else {
                mp2.put(nums2[i], 1);
            }
        }

        for (int key : mp1.keySet()) {
            if (mp2.containsKey(key)) {
                arr.add(key);
            }
        }

        int[] result = new int[arr.size()];

        for (int i = 0; i < arr.size(); i++) {
            result[i] = arr.get(i);
        }

        return result;
    }
}