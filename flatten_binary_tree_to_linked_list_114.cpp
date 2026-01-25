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
    void preorder(TreeNode* root,vector<TreeNode*> &temp)
    {
        if(root==NULL)
        {
            return;
        }

        temp.push_back(root);

        //left
        preorder(root->left,temp);

        //right
        preorder(root->right,temp);

    }
    void flatten(TreeNode* root) {
        if(root==NULL)
        {
            return;
        }
        vector<TreeNode*> temp;
        preorder(root,temp);
        //cout<<temp.size()<<endl;
        for(int i=0;i<temp.size()-1;i++)
        {
            temp[i]->left=NULL;
            temp[i]->right=temp[i+1];
        }
        temp.back()->left=NULL;
        temp.back()->right=NULL;
        //return root;


    }
};