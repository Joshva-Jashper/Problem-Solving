class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string final = "123456789";
        int len = final.size();

        int n = to_string(low).size();
        int m = to_string(high).size();
        int diff = abs(n-m);
        int k = n;

        set<int> result;

        for (int j =0;j<=diff;j++)
        {
            string res="";

            for (int i=0;i<k+j;i++)
            {
                res+=final[i];
            }

            if(stoi(res)>= low && stoi(res)<= high)
                result.insert(stoi(res));

            

            for (int i=k+j;i<len;i++)
            {
                res.erase(res.begin());
                res+=final[i];

                if(stoi(res) >= low && stoi(res)<=high)
                {
                    result.insert(stoi(res));
                }
            } 
        }    
        return vector<int>(result.begin(),result.end());   
    }
};