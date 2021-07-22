long long int count=0;
    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        if(N==1)
        {
            cout<<"move disk "<<N<<" from rod "<< from<<" to rod "<< to<<endl;
            count++;
            return count;
        }
        
        toh(N-1, from, aux, to);
        
        cout<<"move disk "<<N<<" from rod "<< from<<" to rod "<< to<<endl;
        count++;
        
        toh(N-1, aux, to, from);
        
        //return count;
    }


// The above function returns the count of swaps, along with the location of each disc in the swap. smallest disc is numbered as 1 and the largest disc as N
