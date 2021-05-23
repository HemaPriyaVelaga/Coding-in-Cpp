int thirdMax(vector<int>& arr) {
        
        int n=arr.size();
        long long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        if(n==1)
        {
            return arr[0];
        }
        
        for(int i=0;i<n;i++)
        {
            //int x = arr[i];
            if(arr[i]>first)
            {
                third = second;
                second = first;
                first = arr[i];
            }
            else if(arr[i]>second && arr[i]<first)
            {
                third = second;
                second = arr[i];
            }
            else if(arr[i]>third && arr[i]<second)
            {
                third = arr[i];
            }
        }
        
        if(second == LONG_MIN && third == LONG_MIN)
        {
            cout<<"No second and third";
            return first;
        }
        else if(third == LONG_MIN && second>LONG_MIN)
        {
            cout<<"No third"<<endl<<second;
            return first;
        }
        else if(third>LONG_MIN && second>third && first>second)
        {
            return third;
        }
       return 0;
    }

// If thrid max doesnt exist, it returns the first max number
