class Solution {
public:
bool colchec(vector<vector<char>>& board,int j)
    {
        unordered_map <char,bool> mp;
        for(int i=0;i<9;i++)
        {
            if(board[i][j] != '.')
                {if(mp[board[i][j]] == true)
                {
                    //cout<<board[k][l]<<" "<<k<<" "<<l<<endl;
                    return false;
                }
                mp[board[i][j]] = true;}
        }
        return true;
    }
    bool rowchec(vector<vector<char>>& board,int i)
    {
        unordered_map <char,bool> mp;
        for(int j=0;j<9;j++)
        {
            if(board[i][j] != '.')
                {if(mp[board[i][j]] == true)
                {
                    //cout<<board[k][l]<<" "<<k<<" "<<l<<endl;
                    return false;
                }
                mp[board[i][j]] = true;}
        }
        return true;
    }
    bool blockchec(vector<vector<char>>& board,int i,int j)
    {
        unordered_map <char,bool> mp;
        for(int k=i;k<=i+2;k++)
        {
            for(int l= j;l<j+3;l++)
            {
                cout<<k<<" "<<l<<endl;
                if(board[k][l] != '.')
                {if(mp[board[k][l]] == true)
                {
                    
                    return false;
                }
                mp[board[k][l]] = true;}

            }
        }
        cout<<endl;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans=blockchec(board,0,0);
        ans=ans&blockchec(board,0,3);
        ans=ans&blockchec(board,0,6);
        //cout<<ans<<endl;
        ans=ans&blockchec(board,3,0);
        ans=ans&blockchec(board,3,3);
        ans=ans&blockchec(board,3,6);

        ans=ans&blockchec(board,6,0);
        ans=ans&blockchec(board,6,3);
        ans=ans&blockchec(board,6,6);

        //row wise check
        for(int i=0;i<9;i++)
        {
            ans=ans&rowchec(board,i);
        }

        //col wise
        for(int j=0;j<9;j++)
        {
            ans=ans&colchec(board,j);
        }

        return ans;
    }
};