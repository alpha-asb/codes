class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        
        /*
        1. The area of the rectangle must be smaller than the area of the circle.

        2. Every chord of the rectangle will be less than the diameter of the circle.

        3.We can't make the rectangle on the endpoints of the diameter of the cirlce

        If the above conditions satisfies, then the rectangle is inside the circle.
        */
        int len = 2*r -1; // max len of side of rec
        int area = 3.14*(r*r);
        int ans=0;
        for(int i=1;i<= len;i++){
            for(int j=1;j<=len;j++){
                int temp_area = i*j;
                if(temp_area<=area and pow(2*r,2)>=pow(i,2)+pow(j,2)){ans++;}
                else{break;}
            }
        }
        return ans;
    }
};
