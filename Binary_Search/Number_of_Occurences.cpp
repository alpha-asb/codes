class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int lo =0;
	    int hi =n-1;
	    bool flag = false;
	    int mid;
	    while(lo<=hi){
	        mid = lo + (hi-lo)/2;
	        if(arr[mid] == x){
	            flag =true;
	            break;
	        }
	        else if(arr[mid] < x){
	            lo = mid+1;
	        }
	        else{
	            hi = mid-1;
	        }
	    }
	    if(!flag){
	        return 0;
	    }
	    lo = 0;
	    hi = mid;
	    int first;
	    // left index
	    while(lo<=hi){
	        int mid2 = lo + (hi-lo)/2;
	        if(arr[mid2] == x){
	            first = mid2;
	            hi = mid2-1;
	        }
	        else{
	            lo = mid2+1;
	        }
	    }
	    //right index
	    lo = mid;
	    hi = n-1;
	    int second;
	    while(lo<=hi){
	        int mid3 = lo + (hi-lo)/2;
	        if(arr[mid3] == x){
	            second = mid3;
	            lo = mid3+1;
	        }
	        else{
	            hi = mid3-1;
	        }
	    }
	    return second-first+1;
	}
};
