int dif=INT_MAX;
                int nxt;
                for(int j=i;j<nums.size();j++)
                {
                    if(nums[j]>nums[i-1])
                    {
                        if(dif>(nums[j]-nums[i-1]))
                        {
                            dif=nums[j]-nums[i-1];
                            nxt=j;
                        }
                    }
                }
                //cout<<nums[i-1]<<" "<<nums[i]<<" "<<nums[i+1]<<endl;
                //cout<<nxt<<endl;
                swap(nums[i-1],nums[nxt]);
                vector<int> temp;
                for(int j=i;j<nums.size();j++)
                {
                    temp.push_back(nums[j]);
                }
                
                sort(temp.begin(),temp.end());
                //cout<<temp[0]<<" "<<temp[1];
                for(int j=i;j<nums.size();j++)
                {
                    cout<<j<<endl;
                    nums[j]=temp[j-i];
                }