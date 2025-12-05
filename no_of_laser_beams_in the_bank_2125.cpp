class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>device;
        for(auto i : bank)
        {
            int count=0;
            for(auto j : i)
            {
                if(j == '1')
                {
                    count++;
                }
            }
            if(count !=0)
              device.push_back(count);
        }

        int i=0;
        int j=1;
        int ans=0;
        while(i>=0 && j<device.size() && i<j)
        {
            cout<<device[i]<<" "<<device[j]<<endl;
            ans=ans+(device[i]*device[j]);
            i++;
            j++;
        }
        return ans;
    }
};