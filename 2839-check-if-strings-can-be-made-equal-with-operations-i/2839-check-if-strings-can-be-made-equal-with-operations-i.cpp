class Solution {
public:

    bool swapOnly1(string s1,string s2){
        swap(s1[0],s1[2]);
        return s1==s2;
    }
    bool swapOnly2(string s1,string s2){
        swap(s1[1],s1[3]);
        return s1==s2;
    }
    bool swapBoth(string s1,string s2){
        swap(s1[0],s1[2]);
        swap(s1[1],s1[3]);
        return s1==s2;
    }

    bool canBeEqual(string s1, string s2) {
        return  s1==s2||swapOnly1(s1,s2)||swapOnly2(s1,s2)||swapBoth(s1,s2);

    }
};