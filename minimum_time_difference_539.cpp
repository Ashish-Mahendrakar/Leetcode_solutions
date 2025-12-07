class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>time;
        for(auto i : timePoints)
        {
            int one=(int)i[0]  - 48;
            int two=(int)i[1]   - 48;
            int three=int(i[3]) -48;
            int four=(int)i[4] -48;

            int temp=(((one*10)+two)*60 +((three*10)+four));
            cout<<one<<" "<<two<<" "<<three<<" "<<four<<" "<<temp<<endl;
            time.push_back(temp);

        }
        // for(auto i : time)
        // {
        //     cout<<i<<endl;
        // }
        
        sort(time.begin(),time.end());

        int diff=time.back()-time[0] > 720 ? 1440 -time.back()+time[0] :time.back()-time[0];
        for(int i=1;i<time.size();i++)
        {
            int f=time[i-1];
            int s=time[i];

            int d=s-f;
            if(d>720)
            {
                d=1440-d;
            }
            if(d<diff)
            {
                diff=d;
            }
        }

        return diff ;
    }
};