class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i=n;i<=n+10;i++)
        {
            int sum =1;
            int num = i;
            while(num>0)
            {
                int d = num%10;
                sum*=d;
                num=num/10;
            }
            if(sum%t==0)
                return i;
        }
        return 0;
    }
};