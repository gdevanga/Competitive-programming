// Problem description @ https://leetcode.com/problems/count-complete-tree-nodes/

// Feb 25th 2020
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};