class Solution {
public:
    void rr(int i,int left,int right,vector<string> &ans,int &n,string &temp)
    {
        if(left== right && left==n)
        {
            ans.push_back(temp);
            return;
        }

        if(left+1<=n)
        {
           temp.push_back('(');
           rr(i+1,left+1,right,ans,n,temp); 
           temp.pop_back();
        }

        if(left>right)
        {
           temp.push_back(')');
           rr(i+1,left,right+1,ans,n,temp); 
           temp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int i=0;
        int left=0;
        int right=0;
        string temp;
        rr(i,left,right,ans,n,temp);
        return ans;
    }
};