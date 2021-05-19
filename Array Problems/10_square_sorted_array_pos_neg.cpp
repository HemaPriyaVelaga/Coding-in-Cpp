
void merge(vector<int>& arr, int *nums, int low, int mid, int high)
    {
        int i=mid-1, j=low, k = mid;
        while(i>=0 && k<high)
        {
            if((0-arr[i])<arr[k])
            {
                nums[j] = arr[i];
                j++;
                i--;
            }
            else
            {
                nums[j] = arr[k];
                j++;
                k++;
            }
            
        }
        
        while (i>=0)
        {
            nums[j++] = arr[i];
            i--;
        }
        
        while(k<high)
        {
            nums[j++] = arr[k];
            k++;
        }
        
        for(int i=0;i<high;i++)
        {
            arr[i] = nums[i];
        }
        
        
    }
    
    
vector<int> sortedSquares(vector<int>& arr) {
        int pos_ind = 0;
        int n = arr.size();
        int i;
        int nums[n];
        for(i=0;i<n;i++)
        {
            if(arr[i]>=0)
            {
                break;
            }
        }
        
        merge (arr, nums, 0, i, n);
        for(int i=0;i<n;i++)
        {
            arr[i] = arr[i]*arr[i];
        }
        return arr;
        
    }


int main()
{
    vector <int> arr{ -6, -3, -1, 2, 4, 5 };
    int n = arr.size();
 
    cout << "Before sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    sortedSquares(arr);
 
    cout << "\nAfter Sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}
