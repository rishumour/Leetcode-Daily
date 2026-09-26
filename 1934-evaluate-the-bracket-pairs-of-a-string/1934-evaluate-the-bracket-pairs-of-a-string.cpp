class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        string ans = "";
        string key = "";
        bool inKey = false;
        
        for (char c : s) {
            if (c == '(') {
                inKey = true;
                key = "";
            } else if (c == ')') {
                inKey = false;
                if (dict.count(key)) {
                    ans += dict[key];
                } else {
                    ans += '?';
                }
            } else if (inKey) {
                key += c;
            } else {
                ans += c;
            }
        }
        
        return ans;
    }
};