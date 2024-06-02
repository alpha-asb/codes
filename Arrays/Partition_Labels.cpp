class Solution {
public:
    vector<int> partitionLabels(string s) {
        // to keep track of the lasst index of charecters
        vector<int>lastidx(26,0);
        for(int i=0;i<s.size();i++){
            lastidx[s[i]-'a'] = i;
        }
        vector<int> result;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            // maitain end as the max of lastindex
            // find condition : i == end : push in the result; update start = end+1
          // key condition 1
            end = max(end, lastidx[s[i] - 'a']);
          // key condition 2
            if (i == end) {
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};
