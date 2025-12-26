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
class Flag{
    public:
        bool ns;
        bool nns;
        
    Flag()
    {
        this->ns=false;
        this->nns=false;
    }
};
class Solution {
public:
    void los(TreeNode* &root,Flag &ans)
    {
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            if(cur==NULL && !ans.ns)
            {
                ans.ns=true;
            }
            if(cur != NULL  && ans.ns && !ans.nns)
            {
                ans.nns=true;
                return;
            }
            if(cur != NULL )
            {
                q.push(cur->left);
                q.push(cur->right);
            }
           
        }
    }
    bool isCompleteTree(TreeNode* root) {
        Flag ans;
        los(root,ans);
        // if( ans.nns==true)
        // {
        //     return false;
        // }
        return !ans.nns;
    }
};