class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        
        long long totalCommas = 0;
        long long low = 1000;
        long long commas = 1;
        
        while (low <= n) {
            long long tier_end = 1;
            int digits = commas * 3 + 3;
            for (int i = 0; i < digits; ++i) {
                tier_end *= 10;
            }
            tier_end -= 1; 
            
            long long upper = min(n, tier_end);
            if (upper >= low) {
                totalCommas += (upper - low + 1) * commas;
            }
            
            low = tier_end + 1;
            commas++;
        }
        
        return totalCommas;
    }
};