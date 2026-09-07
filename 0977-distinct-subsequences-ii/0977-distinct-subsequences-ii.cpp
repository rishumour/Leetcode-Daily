class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        vector<long long> endsWith(26, 0);
        long long total = 0;
        
        for (char c : s) {
            long long old_endsWith = endsWith[c - 'a'];
            endsWith[c - 'a'] = (total + 1) % MOD;
            total = (total + endsWith[c - 'a'] - old_endsWith + MOD) % MOD;
        }
        
        return total;
    }
};