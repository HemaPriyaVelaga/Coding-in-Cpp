
#include<bits/stdc++.h>
using namespace std;
 

int median(int arr[], int start, int end)
 {
     return arr[(end-start+1)/2];
 }
/* This function returns median 
   of array1[] and array2[].
Assumptions in this function:
    Both array1[] and array2[] are 
    sorted arrays
    Both have n elements */
int getMedian(int first[], int fstart, int fend, int second[], int sstart, int send)
{
     //Practise Yourself : Write your code Here
     if(fend-fstart == 1 && send-sstart == 1)
     {
         float x =max(first[fstart], second[sstart]);
         float y = min(first[fend], second[send]);
         return (x+y)/2;
     }
     
     float m1 = median(first, fstart, fend);
     float m2 = median(second, sstart, send);
     int fmid = (fstart + fend)/2;
     int smid = (sstart + send)/2;
     
     if(m1>m2)
     {
         return getMedian(first, fstart, fmid, second, smid, send);
     }
     else
     {
         return getMedian(first, fmid, fend, second, sstart, smid);
     }
    // return 0;
}


int main()
{
    int array1[] = {1, 6, 8, 10, 12};
    int array2[] = {2, 3, 4, 9, 11};
    int size1 = sizeof(array1) / 
             sizeof(array1[0]);
    int size2 = sizeof(array2) / 
             sizeof(array2[0]);
    if (size1 == size2)
        cout << "Median is "
             << getMedian(array1, 0, size1-1, array2, 0 , size2-1);

    return 0;
}

/* Try more Inputs

case1: 
 actual = getMedian([0,0],[0,0],2)
 expected = 0
 
case2: 
actual = getMedian([2,7],[11,16],2)
expected = 9

case3: 
actual = getMedian([1,2,3,6],[4,6,8,10],4)
expected = 5
*/
