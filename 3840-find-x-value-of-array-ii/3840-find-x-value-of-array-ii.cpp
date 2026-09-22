struct Node {
    int remain[5] = {0};
    int prod = 1;
};

class Solution {
    int k;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node node;
        node.prod = (left.prod * right.prod) % k;
        
        for (int i = 0; i < k; ++i) {
            node.remain[i] = left.remain[i];
        }
        
        for (int i = 0; i < k; ++i) {
            node.remain[(i * left.prod) % k] += right.remain[i];
        }
        
        return node;
    }

    void build(const vector<int>& nums, int node, int left, int right) {
        if (left == right) {
            int val = nums[left] % k;
            tree[node].prod = val;
            tree[node].remain[val] = 1;
            return;
        }
        int mid = left + (right - left) / 2;
        build(nums, 2 * node + 1, left, mid);
        build(nums, 2 * node + 2, mid + 1, right);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int left, int right, int idx, int val) {
        if (left == right) {
            for (int i = 0; i < k; ++i) tree[node].remain[i] = 0;
            int mod_val = val % k;
            tree[node].prod = mod_val;
            tree[node].remain[mod_val] = 1;
            return;
        }
        int mid = left + (right - left) / 2;
        if (idx <= mid) {
            update(2 * node + 1, left, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, right, idx, val);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    Node query(int node, int left, int right, int ql, int qr) {
        if (ql <= left && right <= qr) {
            return tree[node];
        }
        int mid = left + (right - left) / 2;
        if (qr <= mid) {
            return query(2 * node + 1, left, mid, ql, qr);
        } else if (ql > mid) {
            return query(2 * node + 2, mid + 1, right, ql, qr);
        }
        return merge(
            query(2 * node + 1, left, mid, ql, qr),
            query(2 * node + 2, mid + 1, right, ql, qr)
        );
    }

public:
    vector<int> resultArray(vector<int>& nums, int k_val, vector<vector<int>>& queries) {
        k = k_val;
        int n = nums.size();
        tree.resize(4 * n);

        build(nums, 0, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            update(0, 0, n - 1, idx, val);
            Node res = query(0, 0, n - 1, start, n - 1);
            ans.push_back(res.remain[x]);
        }

        return ans;
    }
};