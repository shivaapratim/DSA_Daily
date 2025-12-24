class Solution {
public:

    int mirrorDistance(int n) {
    
        string num= to_string(n);
        reverse(num.begin(),num.end());
        int revNum= stoi(num);
        return abs(revNum-n);

    }
};