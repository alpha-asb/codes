class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
       // if rec1 do not overlap then it must be left,right,up,down to  rec2
       // negation of above condition is for overlap
       // if rec1 || rec2 is line ,then no overlap
        
       if(rec1[0]==rec1[2] || rec1[1]==rec1[3] ||rec2[0]==rec2[2] || rec2[1]==rec2[3]){
           return false;
       }
        return !(rec1[2]<=rec2[0] // rec1 on left
                || rec1[0]>=rec2[2]// rec1 on right
                || rec1[1]>=rec2[3] //rec1 above
                || rec1[3]<=rec2[1] //rec1 below
                );
    }
};
