class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g_time=0;
        int p_time=0;
        int m_time=0;

        int g_status=0;
        int p_status=0;
        int m_status=0;

        for(int i=0;i<garbage.size();i++)
        {
            
            for(auto ch : garbage[i])
            {
                if(ch=='M')
                {
                   
                    m_time++;
                    m_status=i;
                    
                }

                else if(ch=='P')
                {
                    
                    p_time++;
                    p_status=i;
                    
                }


                else
                {
                    
                    g_time++;
                    g_status=i;
                    
                }
                
            }

        }
        for(int i=0;i<g_status;i++)
        {
            g_time=g_time+travel[i];
        }
        for(int i=0;i<p_status;i++)
        {
            p_time=p_time+travel[i];
        }
        for(int i=0;i<m_status;i++)
        {
            m_time=m_time+travel[i];
        }

        return p_time+m_time+g_time;
    }
};