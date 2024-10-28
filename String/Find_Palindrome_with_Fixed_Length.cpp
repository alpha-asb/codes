

class Solution {
public:
    std::vector<int> maxPalindroms;

    // Helper function to fill maxPalindroms for a given length
    int fill(int n) {
        if (n == 1) return 9;
        if (n == 2) return 9;
        if (maxPalindroms[n] != 0) return maxPalindroms[n];  // Avoid recalculating
        return maxPalindroms[n] = 10 * fill(n - 2);
    }

    // Helper function to generate the kth palindrome of a given length
    long long solve(int q, int n) {
        if (q > maxPalindroms[n]) {
            return -1;  // Not enough palindromes of this length
        }
        long long half_pal = pow(10,(n-1)/2);
        half_pal += q;
        half_pal--;
        string s = to_string(half_pal);
        string t = s;
        reverse(t.begin(),t.end());
        if(n%2){s.pop_back();}
        s += t;
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans*10) + (s[i] - '0');
        }
        return ans;
    }

    std::vector<long long> kthPalindrome(std::vector<int>& queries, int intLength) {
        std::vector<long long> res;
        maxPalindroms.resize(16, 0);
        maxPalindroms[1] = 9;
        maxPalindroms[2] = 9;
        for (int i = 1; i <= intLength; ++i) {
            fill(i);
        }
        for(int x:maxPalindroms){
            cout<<x<<" ";
        }
        for (auto q : queries) {
            long long ans = solve(q, intLength);
            res.push_back(ans);
        }
        return res;
    }
};
