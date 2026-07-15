class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evenSum = 0;
        int oddSum =0;

        int i=2,j=1;

        for (auto k =1;k<=n;k++)
        {
            evenSum+=i;
            i+=2;
            oddSum+=j;
            j+=2;
        }
        cout << evenSum<<endl;
        cout << oddSum <<endl;

        return gcd(evenSum,oddSum);
    }
};