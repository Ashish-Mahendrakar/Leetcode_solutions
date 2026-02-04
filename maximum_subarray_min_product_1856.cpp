class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<int> left(nums.size(),-1);
        vector<int> right(nums.size(),-1);
        vector<long long> presum(nums.size(),0);
        //vector<int> postsum(nums.size(),0);

        stack<int> st;
        for(int i=0;i<nums.size();i++)
        {
            if(st.empty())
            {
                st.push(i); 
            }
            else
            {
                while(!st.empty() && nums[i]<=nums[st.top()])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    st.push(i); 
                }
                else
                {
                    left[i]=st.top();
                    st.push(i);
                }
            }


            if(i==0)
            {
                presum[0]=nums[i];
            }
            else
            {
                presum[i]=presum[i-1]+nums[i];
            }
        }

        while(!st.empty())
        {
            st.pop();
        }

        //cout<<st.size()<<endl;

        for(int i=nums.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                st.push(i); 
            }
            else
            {
                while(!st.empty() && nums[i]<=nums[st.top()])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    st.push(i); 
                }
                else
                {
                    right[i]=st.top();
                    st.push(i);
                }
            }


            
        }

        long long ans=LONG_MIN;
        for(int i=0;i<nums.size();i++)
        {
            //cout<<left[i]<<" "<<right[i]<<" "<<presum[i]<<endl;
            long long temp=(long long)nums[i];

            if(left[i]==-1 && right[i]==-1)
            {
                temp=temp*presum[nums.size()-1];
            }
            else if(right[i]==-1)
            {
                temp=temp*(presum[nums.size()-1] - presum[left[i]]);
            }
            else if(left[i]==-1)
            {
                temp=temp*presum[right[i]-1];
            }
            else
            {
                temp=temp*(presum[right[i]-1] - presum[left[i]]);
            }

            if(ans<temp)
            {
                ans=temp;
            }
        }

        ans=ans%(1000000007);


        return (int)ans;
    }
};