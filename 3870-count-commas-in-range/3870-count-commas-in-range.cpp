class Solution {
public:
    int countCommas(int n) {
        string res = to_string(n);
        int len = res.size();
        if (len <=3)
            return 0;

        int cnt = 0;

        for (int i=1000;i<=n;i++)
        {
            string res = to_string(i);
            int len = res.size();
            if (len == 6)
            {
                cnt+=1;
                continue;
            }
            cnt += len/3;
        }    
        return cnt;
    }
};