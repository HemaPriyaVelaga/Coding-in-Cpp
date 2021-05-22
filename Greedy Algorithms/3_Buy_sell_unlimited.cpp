 
void findProfit(vector <int> prices) 
{ 
          
        int n = prices.size();
        int min = prices[0], diff = 0, sum = 0, i=0;
        for(int i=0;i<n-1;i++)
            {
                
                   diff = prices[i+1] - prices[i];
            if(diff>0)
                   sum+=diff;
            }
         return sum; 
  
}


int main() 
{ 
    //int array1[] = { 98, 178, 250, 300, 40, 540, 690 }; // 852
    
    vector <int> array1 = {7,6,4,3,1};
    int n = sizeof(array1) / sizeof(array1[0]); 
  
    cout<<"Max profit: "<<findProfit(array1, n); 
  
    return 0; 
} 

/* Try more Inputs
case 1: 
actual = findProfit([7,1,5,3,6,4],6)
expected = 7

Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3

case2: 
 actual = findProfit([1,2,3,4,5],5)
 expected = 4
 Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4
 
case3: 
actual = findProfit([7,6,4,3,1],5)
expected = 0
In this case, no transaction is done, i.e., max profit = 0
*/
