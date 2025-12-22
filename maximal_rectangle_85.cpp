vector<int> nextsmaller(vector<int>& heights) {
    stack<int> st;
    vector<int> ans(heights.size(), -1);
    
    for (int i = heights.size() - 2; i >= 0; --i) {
        st.push(i+1);
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        
        if (!st.empty()) {
            ans[i] = st.top();
        }

        
    }
    
    return ans;
}

vector<int> prevsmaller(vector<int>& heights)
    {
        stack<int> st;
        vector<int> ans(heights.size(),-1);
        int i=1;
        for(i=1;i<heights.size();i++)
        {
            st.push(i-1);
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
        }
        return ans;
}
int largestRectangleArea(vector<int>& heights) {
        vector<int> nexsmaller=nextsmaller(heights);
        vector<int> presmaller=prevsmaller(heights);
        int max=INT_MIN;
        
        for(int i=0;i<heights.size();i++)
        {
            
            int left=presmaller[i];
            
            int right=heights.size();
            if(nexsmaller[i] != -1)
            {
                right=nexsmaller[i];
            }
            int temp=heights[i]*(right-left-1);
            if(temp>max)
            {
                max=temp;
            }
        }
        return max;
}
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> ref(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix[0].size();i++)
        {
            char temp=matrix[0][i];
            //cout<<temp<<endl;
            
            if(temp == '1')
            {
                //cout<<"hello"<<endl;
                ref[0][i]=1;
            }
            else
            {
                ref[0][i]=0;
            }
            //cout<<ref[0][i]<<endl;
        }
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='1' && ref[i-1][j]!=0)
                {
                    ref[i][j]=ref[i-1][j]+1;
                }
                else
                {
                    if(matrix[i][j]=='1')
                    {
                        ref[i][j]=1;
                    }
                    else
                    {
                    ref[i][j]=0;}
                }
            }
        }
        
        // for(int i=0;i<ref.size();i++)
        // {
        //     for(int j=0;j<ref[0].size();j++)
        //     {
        //         cout<<ref[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int max=INT_MIN;
        for(int i=0;i<ref.size();i++)
        {
            int temp=largestRectangleArea(ref[i]);
            cout<<temp<<endl;
            if(temp>max)
            {
                max=temp;
            }
        }
        return max;
    }
};