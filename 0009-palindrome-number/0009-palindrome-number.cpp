class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string num = to_string(x);
        reverse(num.begin(), num.end());
        long long reversed = stoll(num);
        return x == reversed;
    }
};