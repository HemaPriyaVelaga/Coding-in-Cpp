int removeElement(vector<int>& arr, int val) 
{
   int n = arr.size(), count = 0, j=0;
   for(int i=0;i<n;i++)
   {
      if(arr[i]==val)
      {
         count++;
      }
               
      else
      {
         arr[j] = arr[i];
         j++;
      }
   }
   return n-count;       
}

int main()
{
  vector<int> arr = {0,1,2,2,3,0,4,2}
  int val = 2;
  int end = removeElement(arr, 2);
  for(int i=0;i<end;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}
