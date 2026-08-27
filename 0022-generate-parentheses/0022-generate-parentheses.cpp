class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, n, "", res);
        return res;
    }
    
private:
    void dfs(int open, int close, string curr, vector<string>& res) {
        if (open == 0 && close == 0) {
            res.push_back(curr);
            return;
        }
        
        if (open > 0) {
            dfs(open - 1, close, curr + "(", res);
        }
        if (close > open) {
            dfs(open, close - 1, curr + ")", res);
        }
    }
};