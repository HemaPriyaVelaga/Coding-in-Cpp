#include<bits/stdc++.h> 
  
struct Point 
{ 
    int x, y; 
}; 
  
// Returns true if two rectangles (l1, r1) and (l2, r2) overlap 
bool doOverlap(Point l1, Point r1, Point l2, Point r2) 
{
   if(l1.x>r2.x || l2.x>r1.x)
   {
       return false;
   }
   
   if(l1.y<r2.y || l2.y<r1.y)
   {
       return false;
   }
  
    return true; 
} 
  
int main() 
{ 
    //Point l1 = {0, 10}, r1 = {10, 0}; 
    //Point l2 = {5, 5}, r2 = {15, 0};  // Overlap
    
    //Point l1 = {0,0}, r1 = {2,2}; 
    //Point l2 = {1,1}, r2 = {3,3}; // Dont overlap
    
    Point l1 = {0,0}, r1 = {1,1}; 
    Point l2 = {1,0}, r2 = {2,1}; // Dont overlap
    if (doOverlap(l1, r1, l2, r2)) 
        printf("Rectangles Overlap"); 
    else
        printf("Rectangles Don't Overlap"); 
    return 0; 
}
