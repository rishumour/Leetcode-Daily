class Solution {
public:
    long long countCommas(long long n) {
       long long commas = 0;
        long long base = 1000;
        
        while (n >= base) {
            commas += (n - base + 1);
            
            if (base > 1e15) {
                break;
            }
            base *= 1000;
        }
        
        return commas;
    }
};