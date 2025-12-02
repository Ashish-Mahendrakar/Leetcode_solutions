class Solution {
public:
    string removeOccurrences(string s, string part) {
        int part_len=part.length();
        int index=s.find(part);
        while(index != string :: npos)
        {
            s.erase(index,part_len);
            index=s.find(part);

        }
        return s;
    }
};