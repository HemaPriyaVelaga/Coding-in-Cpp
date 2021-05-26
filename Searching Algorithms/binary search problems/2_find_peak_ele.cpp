 int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int left = 1, right = arr.size()-1;
        if(n<=1)
        {
            return 0;
        }
        else if (n==2)
        {
            if(arr[0]>arr[1])
            {
                return 0;
            }
            else return 1;
        }
        
        
        while(left<=right)
        {
            int mid = right + (left-right)/2;
            
            if((mid==0||arr[mid-1]<arr[mid])&&(mid==arr.size()-1||arr[mid+1]<arr[mid]))
            {
                return mid;
            }
            
            else if(arr[mid]<arr[mid-1] && mid)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        
        return 0;
    }
