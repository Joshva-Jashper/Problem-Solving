class Solution {
public:
    long long sumAndMultiply(int n) {
        int num = n;
        
        int sum =0;

        while(num>0)
        {
            int d =num%10;
            if(d!=0)
            {
                sum=sum*10+d;
            }
            num=num/10;
        }
        
        int r_sum = 0;

        int sum_n=0;

        while(sum > 0)
        {
            int d = sum%10;
            r_sum=r_sum*10+d;
            sum_n +=d;

            sum =sum/10;
        }
        return (long long)sum_n*(long long)r_sum*1LL;
        
    }
};