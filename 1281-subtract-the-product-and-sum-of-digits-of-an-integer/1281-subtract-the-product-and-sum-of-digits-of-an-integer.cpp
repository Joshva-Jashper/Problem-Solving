class Solution {
public:

    int product_(int n)
    {
        int p =1;

        while(n >0)
        {
            int d = n%10;
            p*=d;
            n=n/10;
        }
        return p;
    }

    int sum_(int n)
    {
        int s =0;

        while(n > 0){
            int d =n%10;
            s+=d;
            n=n/10;
        }
        return s;
    }




    int subtractProductAndSum(int n) {
        int product = product_(n);
        int sum = sum_(n);
        return product - sum;
    }
};