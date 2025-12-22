class Solution {
public:
    string simplifyPath(string path) {
        vector <string> st;
        path += '/';
        string tmp = "";
        for(auto i : path){
            if(i == '/'){
                if(tmp == "") continue;
                if(tmp == ".") tmp = "";
                else if(tmp == ".."){
                    if(!st.empty()) st.pop_back();
                }
                else st.push_back(tmp);
                tmp = "";
            }
            else{
                tmp += i;
            }
        }
        string ans = "";

        for(auto i : st){
            ans += '/';
            ans += i;
        }
        if(ans == "") ans = '/';
        return ans;
    }
};