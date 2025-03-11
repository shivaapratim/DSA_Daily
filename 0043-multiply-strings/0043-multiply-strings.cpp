class Solution {   
public:
    const int MOD= 1e9+7;
    string multiply(string num1, string num2) {
        long long a= stoll(num1);
        long long b= stoll(num2);
        long long c= (a*b);

        return to_string(c);
    }
};