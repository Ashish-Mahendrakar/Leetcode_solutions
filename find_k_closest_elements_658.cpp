class Solution {
public:
    int g;
    int find_c(vector<int>&arr,int &x)
    {
        int start=0;
        int end=arr.size()-1;
        int diff=INT_MAX;
        int ans;
        while(start <= end)
        {
            int mid=(start +end)/2;
            if(abs(arr[mid]-x) < diff)
            {
                ans=mid;
                diff=abs(arr[mid]-x);
            }
            else if(abs(arr[mid]-x) == diff)
            {
                if(mid <ans)
                {
                    ans=mid;
                }
            }
            if(arr[mid]>x)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }

        return ans;
    }
    void rr(vector<int>& arr, int &left,int &right,int &temp,int &closest_index)
    {
        //cout<<left<<" "<<right<<" "<<closest_index<<" "<<temp<<endl;
        if(temp==0)
        {
            //cout<<"a";
            return;
        }

        if(left==0)
        {
            //cout<<"b";
            if(right < arr.size()-1)
            {right++;
            temp--;
            rr(arr,left,right,temp,closest_index);}
        }
        else if(right==arr.size()-1)
        {
            //cout<<"c";
            if(left>0)
            {left--;
            temp--;
            rr(arr,left,right,temp,closest_index);}

        }
        else if(left-1>=0 && right+1<arr.size() && g-arr[left-1] < arr[right+1]-g)
        {
            //cout<<"d";
            left--;temp--;
            rr(arr,left,right,temp,closest_index);
        }
        else if(left-1>=0 && right+1<arr.size() && g-arr[left-1] == arr[right+1]-g)
        {
            //cout<<"d";
            left--;temp--;
            rr(arr,left,right,temp,closest_index);
        }
        else
        {
            //cout<<"e";
            right++;
            temp--;
            rr(arr,left,right,temp,closest_index);
        }
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        g=x;
        int closest_index=find_c(arr,x);
        vector<int> ans;
        int temp=k-1;
        int left=closest_index;
        int right=closest_index;
        rr(arr,left,right,temp,closest_index);
        //cout<<left<<" "<<right<<" "<<closest_index<<endl;
        for(int i=left;i<=right;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};