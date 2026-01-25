queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }

        q.push(root);
        q.push(NULL);

        vector<int> temp;

        while(!q.empty())
        {
            TreeNode* t=q.front();
            q.pop();
            if(t==NULL)
            {
                ans.push_back(temp);
                temp.clear();
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                temp.push_back(t->val);
                if(t->left)
                {
                    q.push(t->left);
                }

                if(t->right)
                {
                    q.push(t->right);
                }
            }
        }

        return ans;