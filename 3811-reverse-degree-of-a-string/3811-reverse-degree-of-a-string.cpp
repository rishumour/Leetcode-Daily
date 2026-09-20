class Solution {
public:
    int reverseDegree(string s) {
       int total = 0;
        for (int i = 0; i < s.length(); ++i) {
            int reverse = 26 - (s[i] - 'a');
            total += reverse * (i + 1);
        }
        return total; 
    }
};