class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> table;

    long long dfs(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return 1;
        }

        vector<int> left, right;
        int root = nums[0];
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        long long left_ways = dfs(left) % MOD;
        long long right_ways = dfs(right) % MOD;
        
        long long interleave_ways = table[n - 1][left.size()];
        
        return (((interleave_ways * left_ways) % MOD) * right_ways) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.assign(n, vector<long long>(n, 0));
        
        for (int i = 0; i < n; ++i) {
            table[i][0] = 1;
            table[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }
        
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};