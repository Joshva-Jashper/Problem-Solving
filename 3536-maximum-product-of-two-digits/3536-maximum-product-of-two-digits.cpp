class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        int len = str.size();

        int maxi =INT_MIN;

        for (int i=0;i<len;i++)
        {
            for (int j=i+1;j<len;j++)
            {
                maxi = max(maxi,(str[i]-'0') * (str[j]-'0'));
            }
        }
        return maxi;
    }
};