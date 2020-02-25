//Problem Description @ https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/


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
    int auxFindSecondMinimumValue(TreeNode* root, int rootVal) {
        if (!root)
            return -1;
        if (root->val != rootVal)
            return root->val;
        int min1 = auxFindSecondMinimumValue(root->left, rootVal);
        int min2 = auxFindSecondMinimumValue(root->right, rootVal);
        if (min1 == -1)
            return min2;
        if (min2 == -1)
            return min1;
        return min(min1, min2);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root)
            return -1;
        return auxFindSecondMinimumValue(root, root->val);
    }
};


// Feb 25th 2020
//Doesn't work if INT_MAX is present in tree ex : 2,2,INT_MAX
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
    int auxFindSecondMinimumValue(TreeNode* root, int min) {
        if (!root)
            return INT_MAX;
        if (root->val != min)
            return root->val;
        int min1 = auxFindSecondMinimumValue(root->left, min);
        int min2 = auxFindSecondMinimumValue(root->right, min);
        //cout << " min1 " << min1 << " min2 " << min2 << endl;
        if (min1 > min2)
            return min2;
        else if (min1 < min2)
            return min1;
        else
            return INT_MAX;
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root)
            return -1;
        int min1 = auxFindSecondMinimumValue(root->left, root->val);
        int min2 = auxFindSecondMinimumValue(root->right, root->val);
        if (min1 > min2)
            return min2;
        else if (min1 < min2)
            return min1;
        else if (min1 == INT_MAX)
            return -1;
        else
            return min1;
    }
};


// Iterative - naive
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
    int min(int a, int b)
    {
        if (a > b) return b;
        return a;
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr) return -1;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
         v.push_back(root->val);
        
        while (!q.empty())
        {
            TreeNode* temp = q.front();
            if (temp->left != nullptr /*&& temp->right*/)
            {
                v.push_back(temp->left->val);
                v.push_back(temp->right->val);
                q.push(temp->left);
                q.push(temp->right);
            }
            q.pop();    
        }
        
        if (v.size() < 2)
            return -1;
        
        sort(v.begin(), v.end());
        
        int min = *(v.begin());
        for (vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
        {
           if (*it > min)
               return *it;
        }
        
        return -1;
    }
};