class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int left = 240; // binary 1111 0000
        int right = 15; // binary 0000 1111
        left = (left & n)>>4; //
        right = (right&n)<<4;
        //cout<<left<<" "<<right<<endl;
        return left | right;
    }
};
