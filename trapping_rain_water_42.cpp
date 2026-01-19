class Solution {
public:
    int find(vector<int>& heights,int i,int j)
    {
        int ref=heights[i];
        if(heights[j]<heights[i])
        {
            ref=heights[j];
        }
        int ans=0;
        for(int k=i+1;k<j;k++)
        {
            if(ref>heights[k])
                ans=ans+(ref-heights[k]);
        }
        return ans;
    }
    int trap(vector<int>& heights) {
        int n=heights.size();
        if(n==1 || n==2)
        {
            return 0;
        }
        int first=-1;
        vector<int> pivots;
        if(heights[0]>=heights[1])
        {
           pivots.push_back(0); 
        }
        //cout<<pivots.size()<<endl;
        for(int i=1;i<heights.size()-1;i++)
        {
            if(heights[i]>=heights[i-1] && heights[i]>=heights[i+1])
            {
                pivots.push_back(i);
                //cout<<heights[i]<<endl;

            }
        }
        
        if(heights[heights.size()-1]>=heights[heights.size()-2])
        {
            pivots.push_back(heights.size()-1);
        }
        

        stack <int> q;
        for(int i=0;i<pivots.size();i++)
        {
            if(q.size()<2)
            {
                q.push(pivots[i]);
            }
            else
            {
                int mid=q.top();
                q.pop();
                int left=q.top();
                //cout<<heights[left]<<" "<<heights[mid]<<" "<<heights[pivots[i]]<<endl;
                if(heights[left]>=heights[mid]  && heights[pivots[i]]>=heights[mid] )
                {
                    //q.push(pivots[i]);
                    i--;
                }
                else
                {
                    q.push(mid);
                    q.push(pivots[i]);
                }
            }
        }
        //cout<<q.size();
        vector<int> temp (q.size(),-1);
        pivots=temp;

        for(int i=q.size()-1;i>=0;i--)
        {
            int t=q.top();
            q.pop();
            pivots[i]=t;

        }
        //cout<<q.size();

        int ans=0;
        for(int i=0;i<pivots.size()-1;i++)
        {
            ans=ans+find(heights,pivots[i],pivots[i+1]);
        }
        //cout<<ans<<endl;
        return ans;
    }
};