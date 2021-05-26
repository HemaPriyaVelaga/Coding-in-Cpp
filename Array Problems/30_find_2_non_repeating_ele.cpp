
#include <iostream>
#include <math.h>
using namespace std;


pair<int, int> find2Element(int arr[], int n)
{
    long int exor = arr[0];
    for(int i=1;i<n;i++)
    {
        exor^=arr[i];
    }
    
    long int right_set_bit_mask = exor & ~(exor-1);
    
    long int a=0, b=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] & right_set_bit_mask)
        {
            a^=arr[i];
        }
        else
        {
            b^=arr[i];
        }
    }

	//Write your code here
	
	return make_pair(a,b);
}

// Find two duplicate elements in a limited range array
int main()
{
	int arr[] = { 2,4,7,9,2,4 }; // sol: 7 and 9
	int n = sizeof(arr)/sizeof(arr[0]);
	
	pair<int, int> p = find2Element(arr, n);
	cout << " elements are " << p.first << " and " << p.second;

	return 0;
}

/* Try more Inputs

case1:
actual = find2Element([2,4,7,9,2,4])
expected = 7,9

case2:
actual = find2Element([4,5,4,5,3,2,9,3,9,8])
expected = 2,8

case3:
actual = find2Element([1,1,2,2,3,3,4,5,5,6,7,7])
expected = 6,4
        

*/
