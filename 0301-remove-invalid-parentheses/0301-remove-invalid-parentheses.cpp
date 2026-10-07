class Solution {
bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }

    void dfs(string s, int start, int l_rm, int r_rm, vector<string>& res) {
        if (l_rm == 0 && r_rm == 0) {
            if (isValid(s)) {
                res.push_back(s);
            }
            return;
        }

        for (int i = start; i < s.length(); ++i) {
            if (i > start && s[i] == s[i - 1]) {
                continue;
            }

            if (l_rm > 0 && s[i] == '(') {
                dfs(s.substr(0, i) + s.substr(i + 1), i, l_rm - 1, r_rm, res);
            }
            if (r_rm > 0 && s[i] == ')') {
                dfs(s.substr(0, i) + s.substr(i + 1), i, l_rm, r_rm - 1, res);
            }
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int l_rm = 0, r_rm = 0;
        for (char c : s) {
            if (c == '(') {
                l_rm++;
            } else if (c == ')') {
                if (l_rm > 0) {
                    l_rm--;
                } else {
                    r_rm++;
                }
            }
        }

        vector<string> res;
        dfs(s, 0, l_rm, r_rm, res);
        return res;
    }
};