class Solution {
public:
    bool checkString(string s) {
        int found = 0;
        for (int i=0;i<s.size();i++)
        {
            if (found == 0 and s[i] == 'a')
                continue;
            else if (found == 0 and s[i] == 'b')
            {
                found = 1;
            } 
            else if (found == 1 and s[i] == 'a')
            {
                return false;
            }   
        }
        return true;
    }
};