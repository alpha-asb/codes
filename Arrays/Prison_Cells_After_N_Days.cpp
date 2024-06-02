class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        if(n==0) return cells;
        // this is a trick
        int c = (n-1)%14 + 1;
        cout<<c;
        vector<int> newCell = cells;
        while(c--) {
            for(int i=1; i<7; i++) newCell[i] = !(cells[i-1]^cells[i+1]);
            newCell[0] = 0;
            newCell[7] = 0;
            cells = newCell;
        }
        return cells;
    }
};
