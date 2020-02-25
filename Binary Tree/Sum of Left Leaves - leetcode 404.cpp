// Problem Description @ https://leetcode.com/problems/sum-of-left-leaves/description/
// 25th Feb 2020

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
    int auxSumOfLeftLeaves(TreeNode* root, bool isLeft) {
        if (root == nullptr) 
            return 0;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (isLeft)
                return root->val;
            else
                return 0;
        }
        
        return auxSumOfLeftLeaves(root->left, true) + auxSumOfLeftLeaves(root->right, false);
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root)
            return auxSumOfLeftLeaves(root->left, true) + auxSumOfLeftLeaves(root->right, false);
        else
            return 0;
    }
};


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
    void auxSumOfLeftLeaves(TreeNode* root, int* sum) {
        if (!root)
            return;
        
        if (root->left && root->left->left == nullptr && root->left->right == nullptr) 
            *sum = *sum + root->left->val;
        
        auxSumOfLeftLeaves(root->left, sum);
        auxSumOfLeftLeaves(root->right, sum);
    }
    
public:
    
    int sumOfLeftLeaves(TreeNode* root) {
        int* sum = new int(0);
        auxSumOfLeftLeaves(root, sum) ;
        return *sum;
    }
};



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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while (!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
                if (temp->left->left == nullptr && temp->left->right == nullptr)
                
                    sum += temp->left->val;
            }
            if (temp->right)
                q.push(temp->right);
        }
        return sum;
    }
};