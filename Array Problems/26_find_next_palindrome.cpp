#include <stdio.h> 
  
void printArray (int arr[], int n); 
  

int exceptionCheckAll9s (int num[], int n ); 
  
// Returns next palindrome of a given number num[]. 
// This function is for input type 2 and 3 
void nextPalindromeProblem (int arr[], int n ) 
{ 
     //Practise Yourself : Write your code Here
     int pal[n];
     copy(arr, arr + n, pal);
     
     if(n==1)
     {
         pal[0] =  arr[0]+1;
     }
     
     if(n==2)
     {
         if(arr[0]>arr[1])
         {
             pal[0] = arr[0];
             pal[1] = arr[0];
         }
         else if(arr[0]==arr[1] && arr[0]!=9)
         {
             pal[0] = arr[0]+1;
             pal[1] = pal[0];
         }
     }
     
     
     
     //case1: Even no. of digits
     if(n%2==0)
     {
         // midlefft>midright
         int midleft = (n-1)/2, midright = (n-1)/2 + 1;
         if(pal[midleft]>pal[midright])
         {
             for(i=0;i<n/2;i++)
             {
                 pal[n-i-1] = pal[i];
             }
         }
         
         else if(pal[midleft]<pal[midright])
         {
             pal[midleft]++;
             for(i=0;i<n/2;i++)
             {
                 pal[n-i-1] = pal[i];
             }
             
         }
         else
         {
             while(pal[midleft]==pal[midright] && midleft>=0 && midright <n)
             {
                 midright++;
                 midleft--;
             }
             if(midright == n-1 && midleft ==0 && pal[midright]==pal[midleft])
             {
                  midleft = (n-1)/2, midright = (n-1)/2 + 1;
                  arr[midleft]++;
                  arr[midright]++;
             }
             else
             {
                if(pal[midleft]>pal[midright])
                 {
                    for(i=0;i<n/2;i++)
                     {
                         pal[n-i-1] = pal[i];
                     }
                }
         
                 else if(pal[midleft]<pal[midright])
                 {
                    pal[midleft]++;
                    for(i=0;i<n/2;i++)
                    {
                        pal[n-i-1] = pal[i];
                    }
             
                }
             }
         }
         
     }
     
     else
     {
         int mid = 0 + (n-1)/2;
         if(pal[mid-1]>pal[mid+1])
         {
             for(i=0;i<n/2;i++)
             {
                 pal[n-i-1] = pal[i];
             }
         }
         else if(pal[mid]<pal[mid+1])
         {
             pal[mid]++;
             for(i=0;i<n/2;i++)
             {
                 pal[n-i-1] = pal[i];
             }
             
         }
         
         else
         {
             int midleft = mid-1, midright = mid+1;
             while(pal[midleft]==pal[midright] && midleft>=0 && midright <n)
             {
                 midright++;
                 midleft--;
             }
             if(midright == n-1 && midleft ==0 && pal[midright]==pal[midleft])
             {
                  //midleft = (n-1)/2, midright = (n-1)/2 + 1;
                  arr[mid]++;
                  //arr[midright]++;
             }
             else
             {
                if(pal[midleft]>pal[midright])
                 {
                    for(i=0;i<n/2;i++)
                     {
                         pal[n-i-1] = pal[i];
                     }
                }
         
                 else if(pal[midleft]<pal[midright])
                 {
                    pal[midleft]++;
                    for(i=0;i<n/2;i++)
                    {
                        pal[n-i-1] = pal[i];
                    }
             
                }
             }
         }
     }
     
} 
  
// // The function that prints next palindrome of a given number num[] 
// // with n digits. 
// void generateNextPalindrome( int num[], int n ) 
// { 
//      //Practise Yourself : Write your code Here
//      nextPalindromProblem(num, n);
//      for(int i)
// } 
  

  

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}; 
  
    int n = sizeof (num)/ sizeof(num[0]); 
  
    generateNextPalindrome( num, n ); 
  
    return 0; 
} 


/* Try more Inputs
case 1: 
actual = nextPalindromeProblem([9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2],11)
expected = 94188088149

case2: 
 actual = nextPalindromeProblem([1,2,1],3)
 expected = 131
 
case3: 
actual = nextPalindromeProblem([2,3,5,4,5],5)
expected = 23632
*/
