class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        double m1=double(q1[1]-p1[1])/double(q1[0]-p1[0]);
        double m2=double(q2[1]-p2[1])/double(q2[0]-p2[0]);
        if(m1==m2)  return "false";
        
        bool c1=false,c2=false,c3=false,c4=false;
        if(p2[1]-p1[1]-m1*(p2[0]-p1[0])>0) c1=true;
        if(q2[1]-p1[1]-m1*(q2[0]-p1[0])>0) c2=true;
        if(p1[1]-p2[1]-m2*(p1[0]-p2[0])>0) c3=true;
        if(q1[1]-p2[1]-m2*(q1[0]-p2[0])>0) c4=true;
        
        if((c1 && c2) || (!c1 && !c2)|| (c3 && c4) || (!c3 && !c4))   return "false";
        return "true";
        
        /*
        Approach
The solution involves the following steps:

Calculate Slopes: Compute the slopes of the two line segments.
Check Parallelism: If the slopes are equal, the lines are parallel and do not intersect unless they are collinear.
Orientation Check: Use the orientation of points to determine if the segments intersect.
Code Explanation
Step 1:  Calculate Slopes: The slopes of the two line segments are calculated using the formula:

m1=double(q1[1]-p1[1])/double(q1[0]-p1[0]);
m2=double(q2[1]-p2[1])/double(q2[0]-p2[0]);

Step 2:  Parallelism Check: If m1 == m2, the lines are parallel, and hence, they do not intersect unless collinear, which is not handled here.

Step 3:  Orientation Check:

For line segment p1-q1, we check the orientation of points p2 and q2.
For line segment p2-q2, we check the orientation of points p1 and q1.
If both points p2 and q2 are on the same side of line p1-q1, or if both points p1 and q1 are on the same side of line p2-q2, the segments do not intersect.
        */
    }
};
