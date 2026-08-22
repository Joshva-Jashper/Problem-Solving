
int sum(int n)
{
    int s = 0;
    while(n>0)
    {
        int d = n%10;
        s+=d;
        n=n/10;
    }
    return s;
}

int product(int n)
{
    int s=1;
    while(n>0)
    {
        int d = n%10;
        s*=d;
        n=n/10;
    }
    return s;

}

class Solution {
public:
    bool checkDivisibility(int n) {
        int num = sum(n) + product(n);
        if(n%num==0)
            return true;
        return false;    
    }
};