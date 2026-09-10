/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
int count = 0;
    
    // Helper returns {sum_of_subtree, count_of_nodes}
    pair<int, int> dfs(TreeNode* node) {
        if (!node) {
            return {0, 0};
        }
        
        // Post-order: visit left and right first
        pair<int, int> leftSubtree = dfs(node->left);
        pair<int, int> rightSubtree = dfs(node->right);
        
        int current_sum = leftSubtree.first + rightSubtree.first + node->val;
        int current_count = leftSubtree.second + rightSubtree.second + 1;
        
        // Check if the current node satisfies the condition
        if (node->val == current_sum / current_count) {
            count++;
        }
        
        return {current_sum, current_count};
    }
    
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;  
    }
};