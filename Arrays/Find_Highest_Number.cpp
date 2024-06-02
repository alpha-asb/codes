int start = 0;
    int end = a.size() - 1;
    
    while (start < end) {
        int mid = start + (end - start) / 2;
        
        // Compare middle element with its next element
        if (a[mid] < a[mid + 1]) {
            // If middle element is less than next element, 
            // then the peak must be in the right half
            start = mid + 1;
        } else {
            // If middle element is greater than or equal to next element,
            // then the peak must be in the left half including mid
            end = mid;
        }
    }
