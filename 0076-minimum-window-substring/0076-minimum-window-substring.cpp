class Solution {
public:
    string minWindow(string s, string t) {
        int mini=INT_MAX;
        int l=0,r=0;
        int count =0;
        int len = t.length();
        int len_s = s.length();
        int start =-1;

        unordered_map<char,int> mpp;
        unordered_map<char,int> window;

        for (int i=0;i<len;i++) mpp[t[i]]++;
        int required = mpp.size();

        while(r<len_s)
        {
            if(mpp.find(s[r])!=mpp.end())
            {
                window[s[r]]++;
                if(mpp[s[r]]== window[s[r]])
                    count++;
            }
            while(count==required)
            {
                if(r-l+1<mini)
                {
                 mini= r-l+1;  
                 start= l;
                }

                char c = s[l];

                if(window.find(c)!=window.end())
                {
                    window[s[l]]--;

                    if(window[s[l]]<mpp[s[l]])
                        count--;
                }
                l++;
            }
            r++;
        }
        if(start==-1)
            return "";
        return s.substr(start,mini);
    }
};