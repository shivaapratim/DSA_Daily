import java.util.*;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) j++;
                else if(sum > 0) k--;
                else{
                    ans.add(Arrays.asList(nums[i], nums[j], nums[k]));

                    int s = j;
                    while(j < k && nums[j] == nums[s]) j++;

                    s = k;
                    while(j < k && nums[k] == nums[s]) k--;
                }
            }
        }
        return ans;
    }
}