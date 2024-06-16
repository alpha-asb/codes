class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
        // first find the prime numbers till n
        // them the problem reduce to two sum
        
        vector<bool>isPrime(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;

        //Sieve of Eratosthenes algorithm to find all primes up to n  O(n log log n)
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        // now two sum  O(n)
        for(int i=0;i<=n;i++){
            if(isPrime[i]==true && isPrime[n-i]==true){return {i,n-i};}
        }
        return {-1,-1};
    }
};
