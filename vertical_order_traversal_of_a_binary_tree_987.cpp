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
    void rr(TreeNode* root,int vl,int hl,map<int,vector<pair<int,int>>> &mp)
    {
        if(root == NULL)
        {
            return;
        }
        pair<int,int> temp;
        temp.first=root->val;
        temp.second=hl;
        mp[vl].push_back(temp);

        rr(root->left,vl-1,hl+1,mp);
        rr(root->right,vl+1,hl+1,mp);

    }
    static bool mycom(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.second == b.second)
        {
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> mp;
        int vl=0;
        int hl=0;
        rr(root,vl,hl,mp);
        for(auto i : mp)
        {
            sort(i.second.begin(),i.second.end(),mycom);
            vector<int>temp;
            for(auto n : i.second)
            {
                temp.push_back(n.first);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};