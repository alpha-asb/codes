class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers;
        int currentNumber = 1;

        // Generate numbers from 1 to n
        for (int i = 0; i < n; ++i) {
            lexicographicalNumbers.push_back(currentNumber);

            // If multiplying the current number by 10 is within the limit, do
            // it
            if (currentNumber * 10 <= n) {
                currentNumber *= 10;
            } else {
                // Adjust the current number by moving up one digit
                while (currentNumber % 10 == 9 || currentNumber >= n) {
                    currentNumber /= 10;  // Remove the last digit
                }
                currentNumber += 1;  // Increment the number
            }
        }

        return lexicographicalNumbers;
    }
};


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>res(n);
        int x =1;
        for(int i=0;i<n;i++){
            res[i] =x;
            if(x*10 <= n){
                x*=10;
            }
            else{
                if (x==n) x/=10; // last number
                x++;             // for processing next digit
                while(x%10==0) x/=10;  // removing trailing zeros
            }
        }
        return res;
    }
};
