
int sum(int n)
{
    int s = 0;
    int f = 1;
    while(n>0)
    {
        int d = n%10;
        s+=d;
        f*=d;
        n=n/10;
    }
    return s+f;
}





class Solution {
public:
    bool checkDivisibility(int n) {
        int num = sum(n);
        if(n%num==0)
            return true;
        return false;    
    }
};