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
    void rr(TreeNode* root, int &targetSum,int &sum,bool & ans)
    {
        if(root ==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            //cout<<sum+root->val<<endl;
            if(targetSum==sum+root->val)
            {
                //cout<<"h"<<endl;
                ans=true;
            }
            return;
        }

        sum=sum+root->val;
        //left
        rr(root->left,targetSum,sum,ans);
        sum=sum-root->val;
        sum=sum+root->val;
        //right
        rr(root->right,targetSum,sum,ans);
        sum=sum-root->val;


    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans=false;
        rr(root,targetSum,sum,ans);
        return ans;
    }
};