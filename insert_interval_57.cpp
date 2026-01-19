class Solution {
public:
    vector<int> find(vector<int> a,vector<int> b)
    {
        if(a[0]<=b[0])
        {
            //cout<<"j";
            a[1]=max(b[1],a[1]);
            //cout<<a[0]<<" "<<a[1]<<endl;
            return a;
        }
        else
        {
            b[1]=max(b[1],a[1]);
            //cout<<b[0]<<" "<<b[1]<<endl;
            return b;
        }
    }
    bool check(vector<int> &a,vector<int> &b)
    {
        if(a[0]<=b[0])
        {
            //cout<<"j";
            if(a[1]>=b[0])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(b[1]>=a[0])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        stack <vector<int>> s;
        if(intervals.size()==0)
        {
            return intervals;
        }
        sort(intervals.begin(),intervals.end());

        //s.push(intervals[0]);
        //cout<<"j";
        for(int i=0;i<intervals.size();i++)
        {

            if(s.empty())
            {
                s.push(intervals[i]);
                continue;
            }
            bool status=check(s.top(),intervals[i]);
            //cout<<status<<endl;

            if(status )
            {
                intervals[i]=find(s.top(),intervals[i]);
                //cout<<intervals[i][0]<<" "<<intervals[i][1];
                s.pop();
                i--;
            }
            else
            {
                s.push(intervals[i]);
            }
            //cout<<"i"<<i<<endl;
        }
        //cout<<s.size();
        vector<vector<int>> ans(s.size());
        int n=s.size()-1;
        while(n>=0)
        {
            ans[n]=s.top();
            s.pop();
            n--;
        }
        // int start=0;
        // int end=intervals.size()-1;
        // while(start < end)
        // {
        //     swap(intervals[start],intervals[end]);
        //     start++;
        //     end--;
        // }

        return ans;
    }
};