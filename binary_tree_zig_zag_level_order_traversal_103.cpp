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
    void reverse(vector<int> & temp)
    {
        int end=temp.size()-1;
        int start=0;
        while(start < end)
        {
            swap(temp[start],temp[end]);
            start++;
            end--;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        if(root == NULL)
        {
            return ans;
        }
        vector<int>temp;
        while(!q.empty())
        {
            if(q.front() !=NULL)
            {
                temp.push_back(q.front()->val);
                if(q.front()->left != NULL)
                    q.push(q.front()->left);
                if(q.front()->right != NULL)
                    q.push(q.front()->right);
                q.pop();
            }
            else
            {
                q.pop();
                if(!q.empty())
                {
                    q.push(NULL);
                }
                ans.push_back(temp);
                vector<int>temp1;
                temp=temp1;
            }
        }
        for(int i=1;i<ans.size();i=i+2)
        {
            reverse(ans[i]);
        }
        return ans;
    }
};