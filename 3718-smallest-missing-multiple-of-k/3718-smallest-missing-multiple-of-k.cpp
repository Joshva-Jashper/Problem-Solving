class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bool found = true;

        set<int>st(nums.begin(),nums.end());

        int n=k;


        while(found)
        {
            if(st.find(n)!=st.end())
            {
                n=n+k;
            }
            else
            {
                return n;
                found = false;
            }
        }
        return 0;
    }
};