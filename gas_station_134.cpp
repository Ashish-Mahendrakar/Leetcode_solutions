class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        for(int i=0;i<gas.size();i++)
        {
            gas[i]=gas[i]-cost[i];
            sum=sum+gas[i];
        }
        //cout<<sum;
        if(sum<0)
            return -1;

        int max=gas.back();
        int ans=gas.size()-1;
        for(int i=gas.size()-2;i>=0;i--)
        {
            gas[i]=gas[i]+gas[i+1];
            if(gas[i]>max)
            {
                ans=i;
                max=gas[i];
            }
        }
        
    return ans;

    }
};