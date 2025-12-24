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
    void rr(TreeNode* root, int &targetSum,int &sum,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->left==NULL && root->right==NULL)
        {
            if(sum+root->val==targetSum)
            {
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
            return;
        }

        //
        sum=sum+root->val;
        temp.push_back(root->val);
        rr(root->left,targetSum,sum,temp,ans);
        rr(root->right,targetSum,sum,temp,ans);
        sum=sum-root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        rr(root,targetSum,sum,temp,ans);
        return ans;
    }
};