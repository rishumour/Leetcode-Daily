class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n = s.length();
        int i = n - 1;
        
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            if (i < 0) break;
            
            int j = i;
            while (i >= 0 && s[i] != ' ') {
                i--;
            }
            
            if (!res.empty()) {
                res += ' ';
            }
            res += s.substr(i + 1, j - i);
        }
        
        return res;
    }
};