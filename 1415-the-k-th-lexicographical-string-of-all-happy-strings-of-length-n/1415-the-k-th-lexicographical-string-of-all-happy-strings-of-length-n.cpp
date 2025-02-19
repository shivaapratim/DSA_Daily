class Solution {
public:
    void solve(string s, vector<string>& arr, int n) {
        if (s.length() == n) {
            arr.push_back(s);
            return;
        }

        if (s.empty() || s.back() != 'a') solve(s + 'a', arr, n);
        if (s.empty() || s.back() != 'b') solve(s + 'b', arr, n);
        if (s.empty() || s.back() != 'c') solve(s + 'c', arr, n);
    }

    string getHappyString(int n, int k) {
        vector<string> arr;
        solve("", arr, n);
        if (arr.size() < k) return "";
        return arr[k - 1];
    }
};
