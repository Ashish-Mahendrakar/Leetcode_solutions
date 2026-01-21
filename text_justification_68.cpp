class Solution {
public:
    void format(pair<int,int> ind,vector<string>& words,int &maxWidth,vector<string>& ans)
    {
        int sum=0;
        for(int i=ind.first;i<=ind.second;i++)
        {
            sum=sum+words[i].length();
        }
        
        int gap=maxWidth-sum;
        int n_1=ind.second-ind.first;

        if(n_1 == 0)
        {
            string temp(gap,' ');
            string temp1=words[ind.second];
            
            temp1=temp1+temp;
            
            ans.push_back(temp1);
            return;
        }
        //cout<<gap<<" "<<n_1<<endl;

        vector<string> mid(n_1);
        int mid_i=0;
        while(gap > 0)
        {
            //cout<<gap<<" "<<mid_i<<" "<<n_1<<endl;
            gap--;
            mid[mid_i].push_back(' ');
            mid_i++;
            mid_i=mid_i % n_1;
        }

        // for(auto i : mid)
        // {
        //     cout<<i.length()<<endl;
        // }
        // cout<<endl;
        mid_i=0;
        int i=ind.first;
        string temp="";
        while(mid_i <n_1)
        {
            temp=temp+words[i]+mid[mid_i];
            //cout<<temp<<endl;
            i++;
            mid_i++;

        }
        temp=temp+words[i];
        //cout<<temp.length()<<endl;
        ans.push_back(temp);
    }
    int findlst(int i,int j,vector<string>& words,int sum,int &maxWidth)
    {
        //cout<<i<<" "<<j<<" "<<sum<<" ";
        int n_1=j-i;
        if(n_1 == 0)
        {
            //cout<<j<<endl;
            return j;
        }
        //cout<<n_1<<endl;

        int gap=maxWidth-sum;
        //cout<<sum<<endl;
        if(gap==0)
        {
            gap=gap+words[j].length();
            n_1--;
            j--; 
        }
        //cout<<n_1<<" "<<j<<endl;

        while(gap < n_1)
        {
            gap=gap+words[j].length();
            n_1--;
            j--;
        }

        //cout<<j<<endl;
        return j;


    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<pair<int,int>> ref;
        int i=0;
        int j=0;
        int sum=words[0].length();
        while(j<=words.size()-1)
        {
            //find max word
            
            while( (j+1)<words.size()  && ( (sum + words[j+1].size()) <= maxWidth) )
            {
                //cout<<sum<<endl;
                sum=sum+words[j+1].size();
                j++;
            }

            int k=findlst(i,j,words,sum,maxWidth);
            pair<int,int> temp;
            temp.first=i;
            temp.second=k;
            ref.push_back(temp);
            //cout<<i<<" "<<j<<" "<<k<<endl;
            //cout<<endl;
            i=k+1;
            j=k+1;
            if(j<words.size())
            {
                sum=words[j].length();
            }
            else
            {
                sum=0;
            }
            

        }
        
        
        vector <string> ans;
        for(int i=0;i<ref.size()-1;i++)
        {
            format(ref[i],words,maxWidth,ans);
        }

        pair<int,int> last=ref.back();
        string temp;
        for(int i=last.first;i<=last.second;i++)
        {
            temp=temp+words[i]+" ";
        }
        temp.pop_back();
        int gap=maxWidth-temp.length();
        while(gap>0)
        {
            gap--;
            temp=temp+" ";
        }
        //cout<<temp.length();
        ans.push_back(temp);

        return ans;
    }
};