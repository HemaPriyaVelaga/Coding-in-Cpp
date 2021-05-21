#include <iostream>
 
// Function to return majority element, if present in given array, else returns -1
int majorityElement(int arr[], int n)
{
  
    int maj = arr[0], count = 1;
  
  // Loop to find the majority element
    for(int i=0;i<n;i++)
    {
        if(maj==arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        
        if(count==0)
        {
            maj = arr[i];
            count = 1;
        }
    }
  
   // Now, checking whether the obtained majority element occurs more than n/2 times or not
   int maj_count=0;
   for(int i=0;i<n;i++)
   {
       if(arr[i]==maj)
       {
           maj_count++;
       }
   }
   if(maj_count > n/2)
   {
       return maj;
   }
   else return -1;
   
}

 
int main(void)
{
    int arr[] = { 3, 8, 3, 3, 1, 2, 2, 2, 2, 2, 2 }; // ans = 2
  // int arr[] = { 3, 8, 3, 3, 1, 2, 2, 2 }; // ans = -1
  
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Majority element is %d", majorityElement(arr, n));
 
    return 0;
}
