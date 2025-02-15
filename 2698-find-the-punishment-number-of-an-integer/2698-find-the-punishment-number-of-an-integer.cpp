class Solution {
public:
    bool solve(string x, int i, int target, int current_sum) {
         
        if (i >= x.length()) {
            return current_sum == target;
        }
        
        int num = 0;
        for (int j = i; j < x.length(); j++) {
            num = num * 10 + (x[j] - '0');
            if (solve(x, j + 1, target, current_sum + num)) {
                return true;
            }
        }
        
        return false;
    }

    int punishmentNumber(int n) {
        int result = 0;

        for (int i = 1; i <= n; i++) {
            long long square = (long long)i * i;
            string square_str = to_string(square);
            if (solve(square_str, 0, i, 0)){
                result += square;
            }
        }

        return result;
    }
};