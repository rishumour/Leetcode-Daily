class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        
        for (char c : s) {
            if (c == '(') {
                cmin++;
                cmax++;
            } else if (c == ')') {
                cmin--;
                cmax--;
            } else if (c == '*') {
                cmin--;
                cmax++;
            }
            
            if (cmax < 0) {
                return false;
            }
            if (cmin < 0) {
                cmin = 0;
            }
        }
        
        return cmin == 0;
    }
};