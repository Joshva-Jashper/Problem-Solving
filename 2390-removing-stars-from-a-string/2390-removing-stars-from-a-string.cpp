class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (auto it:s)
        {
            if (it == '*' && !st.empty())
            {
                st.pop();
            }
            else if (it =='*')
                continue;
            else
                st.push(it);
        }
        string res ="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};