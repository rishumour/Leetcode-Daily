class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {0};
        for (int digit : digits) {
            count[digit]++;
        }
        
        int valid_count = 0;
        for (int i = 100; i <= 998; i += 2) {
            int hundreds = i / 100;
            int tens = (i / 10) % 10;
            int ones = i % 10;
            
            count[hundreds]--;
            count[tens]--;
            count[ones]--;
            if (count[hundreds] >= 0 && count[tens] >= 0 && count[ones] >= 0) {
                valid_count++;
            }
            count[hundreds]++;
            count[tens]++;
            count[ones]++;
        }
        
        return valid_count;
    }
};