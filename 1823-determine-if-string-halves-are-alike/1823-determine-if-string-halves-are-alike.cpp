class Solution {
public:
    bool halvesAreAlike(string s) {
        int balance = 0;
        int mid = s.length() / 2;
        
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                if (i < mid) {
                    balance++;
                } else {
                    balance--;
                }
            }
        }
        
        return balance == 0;
    }
};