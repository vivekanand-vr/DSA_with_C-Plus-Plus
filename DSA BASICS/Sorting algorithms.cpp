#include<bits/stdc++.h>
using namespace std;

//Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
       for (int i = 0; i<n-1; i++)
            for (int j = 0; j<n-i-1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }

//Function to sort the array using selection sort algorithm.
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx]) 
            min_idx = j; 
        }
        swap(arr[min_idx], arr[i]); 
    } 
} 

// Function to sort an array using 
// insertion sort
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 

        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

// Shell Sort Algorithm
void shellSort(int arr[], int n) 
{
   for(int gap=n/2; gap>=1; gap=gap/2)
   {
       for(int i=gap; i<n; i+=gap)
       {
           int j=i, key=arr[i];
           while(((j-gap)>=0) and (arr[j-gap]>key))
           {
               arr[j]=arr[j-gap];
               j=j-gap;
           }
           
           arr[j]=key;
       }
   }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function for heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

//Counting Sort Algorithm
void countSort(vector <int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    
    vector<int> count(range), output(arr.size());
    for(int i = 0; i < arr.size(); i++)
        count[arr[i]-min]++;
        
    for(int i = 1; i < count.size(); i++)
           count[i] += count[i-1];
  
    for(int i = arr.size()-1; i >= 0; i--)
    { 
         output[ count[arr[i]-min] -1 ] = arr[i]; 
              count[arr[i]-min]--; 
    }
    
    for(int i=0; i < arr.size(); i++)
            arr[i] = output[i];
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = *max_element(arr, arr+n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


/* This function takes last element as pivot, places the pivot element at its correct position in sorted
   array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
   arr[] --> Array to be sorted,
   low  --> Starting index,
   high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Bucket Sort
void bucketSort(float arr[], int n)
{
    vector<float> b[n];

    // 2) Put array elements 
    // in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}


//Merge Sort
void merge(int arr[], int l, int m, int r)
    {
         int i = l;
         int j = m+1;
         int new_arr[]=new int[(r-l+1)];
         for(int k = 0 ; k <(r-l+1);k++){
             if(i > m){
                 new_arr[k] = arr[j++]; 
             }else if(j > r){
                 new_arr[k] = arr[i++];
             }else if(arr[i]<arr[j]){
                 new_arr[k] = arr[i++];
             }else {
                 new_arr[k] = arr[j++];
             }
         }
         for(int  val :new_arr){
             arr[l++] = val;
         }
    }
void mergeSort(int arr[], int l, int r)
{
    if(l>=r)return;
    int mid  = ( l + r ) / 2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}