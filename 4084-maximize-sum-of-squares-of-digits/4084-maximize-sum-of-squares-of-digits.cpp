class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9LL * num) {
            return "";
        }
        
        int nines = sum / 9;
        int rem = sum % 9;
        
        string ans = "";
        ans.reserve(num);
        
        ans.append(nines, '9');
        if (rem > 0) {
            ans.push_back('0' + rem);
        }
        
        int zeros = num - ans.length();
        if (zeros > 0) {
            ans.append(zeros, '0');
        }
        
        return ans;
    }
};