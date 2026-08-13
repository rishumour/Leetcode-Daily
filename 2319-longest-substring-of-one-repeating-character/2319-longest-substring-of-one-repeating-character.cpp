struct Node {
    int len;
    int pref;
    int suff;
    int max_len;
    char left_char;
    char right_char;
};

class Solution {
    vector<Node> tree;

    Node merge(const Node& l, const Node& r) {
        Node res;
        res.len = l.len + r.len;
        res.left_char = l.left_char;
        res.right_char = r.right_char;
        
        res.pref = l.pref;
        if (l.pref == l.len && l.right_char == r.left_char) {
            res.pref += r.pref;
        }
        
        res.suff = r.suff;
        if (r.suff == r.len && r.left_char == l.right_char) {
            res.suff += l.suff;
        }
        
        res.max_len = max(l.max_len, r.max_len);
        if (l.right_char == r.left_char) {
            res.max_len = max(res.max_len, l.suff + r.pref);
        }
        
        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, c, c};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, c);
        } else {
            update(2 * node + 1, mid + 1, end, idx, c);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
        
        int k = queryCharacters.length();
        vector<int> ans(k);
        
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].max_len;
        }
        
        return ans;
    }
};