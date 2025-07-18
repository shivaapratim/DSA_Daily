class Solution {
public:
    typedef long long ll;

    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 3;

        
        vector<ll> left(N);
         
        priority_queue<ll> maxH;
        ll left_sum = 0;

        for (int i = 0; i < N; ++i) {
            left_sum += nums[i];
            maxH.push(nums[i]);
            
             
            if (maxH.size() > n) {
                left_sum -= maxH.top();
                maxH.pop();
            }

             
            if (maxH.size() == n) {
                left[i] = left_sum;
            }
        }

         
        vector<ll> right(N);
         
        priority_queue<ll, vector<ll>, greater<ll>> minH;
        ll right_sum = 0;

        for (int i = N - 1; i >= 0; i--) {
            right_sum += nums[i];
            minH.push(nums[i]);

             
            if (minH.size() > n) {
                right_sum -= minH.top();
                minH.pop();
            }
             
            if (minH.size() == n) {
                right[i] = right_sum;
            }
        }
 
        ll min_diff = LLONG_MAX;

         
        for (int i = n - 1; i < 2 * n; i++) {
            ll current_diff = left[i] - right[i + 1];
            min_diff = min(min_diff, current_diff);
        }

        return min_diff;
    }
};