ll findSubarray(vector<ll> arr, int n ) // ll= long long
{
        //code here
        unordered_map<int, vector<int> > map;
        vector <pair<int, int>> out;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)
            {
                out.push_back(make_pair(0, i));
            }
            
            if (map.find(sum) != map.end())
            {
            // map[sum] stores starting index of all subarrays
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
            }
   
        // Important - no else
            map[sum].push_back(i);
            }
   
    // returns count of output vector which is the count of zero sum subarrays
  // To return the index of the subarrays, return the vector out directly instead of performing the size operation
    return out.size();
    }
