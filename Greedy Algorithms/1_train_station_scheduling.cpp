
#include<iostream>
#include<algorithm>
using namespace std;

int minPlatform(int arrival[], int departure[], int n) 
{
   int i=1,j=0, platform_needed=1, max_plat = 1;
   sort(arrival, arrival+n);
   sort(departure, departure+n);
   
   while(i<n && j<n)
   {
       if(arrival[i]<=departure[j])
       {
           platform_needed++;
           i++;
           
           if(platform_needed>max_plat)
           {
               max_plat = platform_needed;
           }
       }
       
       else
       {
           platform_needed--;
           j++;
       }
   }
   return max_plat;
   return 0;
}


int main() {
   int arrival[] = {900, 940, 950, 1100, 1500, 1800};
   int departure[] = {910, 1200, 1120, 1130, 1900, 2000};
   int n = 6;
   cout << "Minimum Number of Platforms Required: " << minPlatform(arrival, departure, n);
}

/* Try more Inputs
case 1: 
actual = minimumNumberOfPlatform([900,940,950,1100,1500,1800],[910, 1200, 1120, 1130, 1900, 2000],6)
expected = 3

case2: 
actual = minimumNumberOfPlatform([200, 210, 300, 320, 350, 500],[230, 340, 320, 430, 400, 520],6)
expected = 3
 
case3: 
actual = minimumNumberOfPlatform([900, 1100, 1235],[1000, 1200, 1240],3)
expected = 1
*/


