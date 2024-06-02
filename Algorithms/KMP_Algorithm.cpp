class Solution
{
    public:
        void computeLPS(int n,string pat,vector<int>&lps){
            int len =0;
            lps[0] = 0;
            int i = 1;
            while(i<n){
                if(pat[i]==pat[len]){
                    lps[i] = len+1;
                    len++;
                    i++;
                }
                else{
                    if(len!=0){
                        len = lps[len-1];
                    }
                    else{
                        lps[i] = 0;
                        i++;
                    }
                }
            }
            return;
        }
        vector <int> search(string pat, string txt)
        {
            //code here
            int n = pat.size();
            int m = txt.size();
            vector<int>lps(n,0);
            
            computeLPS(n,pat,lps);
            // for(auto x:lps){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            vector<int>res;
            int i =0;
            int j =0;
            
            while(i < m){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                }
                else{
                    if(j!=0){
                        j = lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
                if(j == n){
                    res.push_back(i-j+1);
                    j = lps[j-1];
                }
            }
            return res;
        }
     
};
