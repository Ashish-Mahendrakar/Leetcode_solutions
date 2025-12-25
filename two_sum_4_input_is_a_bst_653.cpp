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
public:
    void inorder(TreeNode* root,vector<int> &ord)
    {
        if(root == NULL)
        {
            return;
        }

        inorder(root->left,ord);

        ord.push_back(root->val);

        inorder(root->right,ord);


    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ord;
        inorder(root,ord);
        int start=0;
        int end=ord.size()-1;
        while(start < end)
        {
            int value=ord[start]+ord[end];
            if(value==k)
            {
                return true;
            }
            else if(value>k)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        return false;
    }
};