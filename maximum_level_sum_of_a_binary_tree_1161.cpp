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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int ans=0;
        int level=1;
        int sum=0;
        int max=INT_MIN;

        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();

            if(temp)
            {
                sum=sum+temp->val;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            else
            {
                if(sum>max)
                {
                    max=sum;
                    ans=level;
                }
                if(!q.empty())
                {
                    q.push(NULL);
                }
                sum=0;
                level++;
            }
        }

        return ans;
    }
};