#include<bits/stdc++.h>
using namespace std;

//Function to fill the array elements into a hash table 
    //using Linear Probing to handle collisions.
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
        vector<int>hash(hashSize, -1);
        for(int i=0; i<sizeOfArray; i++)
        {
            int t = arr[i]%hashSize;
            if(hash[t]==-1 or hash[t]==arr[i])
            {
                hash[t]=arr[i];
            }
            
            else
            {
                int ptr = (t+1)%hashSize;
                while(ptr!=t)
                {
                    if(hash[ptr]==-1)
                    {
                        hash[ptr]=arr[i];
                        break;
                    }
                    
                    if(hash[ptr]==arr[i])
                    {
                        break;
                    }
                    ptr = (ptr+1)%hashSize;
                }
            }
        }
        
        return hash;
    }

 //Function to fill the array elements into a hash table 
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector <int>&hash, int hashSize, int arr[], int N)
    {
        for(int i=0; i<N; i++)
        {
            int t = arr[i]%hashSize;
            int j=0;
            while(1)
            {
                int ptr = (t+(j*j))%hashSize;
                if(hash[ptr]==-1 or hash[ptr]==arr[i])
                {
                    hash[ptr]=arr[i];
                    break;
                }
                
                j++;            }
        }
    }