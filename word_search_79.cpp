class Solution {
public:
    bool rr(vector<vector<bool>> &flag,vector<vector<char>>& board,int i,int j,int k,string &word)
    {
        if(k==word.length()-1)
        {
            return true;
        }
        flag[i][j]=true;

        bool status=false;
        int m=board.size();
        int n=board[0].size();

        //up
        if(i>=1 && flag[i-1][j]==false && board[i-1][j]==word[k+1])
        {
            status=status|rr(flag,board,i-1,j,k+1,word);
        }

        //down
        //cout<<(i <= (m-2))<<" "<<i<<" "<<(m - 2)<<endl;
        if(i<=m-2 && flag[i+1][j]==false && board[i+1][j]==word[k+1])
        {
            status=status|rr(flag,board,i+1,j,k+1,word);
        }

        //left
        if(j>=1 && flag[i][j-1]==false && board[i][j-1]==word[k+1])
        {
            status=status|rr(flag,board,i,j-1,k+1,word);
        }

        //right
        if(j<=n-2 && flag[i][j+1]==false && board[i][j+1]==word[k+1])
        {
            status=status|rr(flag,board,i,j+1,k+1,word);
        }
        flag[i][j]=false;
        return status;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() > (board.size()*board[0].size()))
        {
            return false;
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {

                if(board[i][j]==word[0])
                {
                    vector<vector<bool>> flag(board.size(),vector<bool>(board[0].size(),false));

                    cout<<i<<" "<<j<<endl;
                    bool status=rr(flag,board,i,j,0,word);
                    
                    if(status)
                    {
                        return status;
                    }
                }
                
            }
        }
        return false;
    }
};