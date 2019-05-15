#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
using std::vector;

/************************Function Prototype************************/
template <class T>
void mergeSort(vector<T>&, bool (*compare)(const T&, const T&));

template <class T>
void mergeSort(vector<T>&, int, int, bool (*compare)(const T&, const T&));

template <class T>
void merge(vector<T>&, int, int, int, bool (*compare)(const T&, const T&));


/********************************************************************
mergeSort()
Use:function calls the recursive merge sort function
Parameters:reference to a vector obj and pointer to a comparison function
Returns:nothing
**********************************************************************/
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
  mergeSort(set, 0, set.size() -1, compare);
}

/********************************************************************
mergeSort()
Use:divided two vectors into two subvectors and sorts them
Parameters:reference to a vector obj, integer low represents right side,
int high represents left side, pointer to a comparison function
Returns: nothing
**********************************************************************/
template <class T>
void mergeSort(vector<T>& set, int low, int high, bool (*compare)(const T&, const T&))
{
    int mid;
   
   if (low < high)
      {
      mid = (low + high) / 2;
      
      // Divide and conquer
      
      mergeSort(set, low, mid, compare);
      mergeSort(set, mid+1, high, compare);
      
      // Combine
      merge(set, low, mid, high, compare);
      }

}

/********************************************************************
merge()
Use:function merges two sorted subvectors
Parameters:reference to a vector object, int ,int int, and pointer
to a comparison function
Returns:nothing
**********************************************************************/

template <class T>
void merge(vector<T>& set, int low, int mid, int high, bool (*compare)(const T&, const T&))
{
   // Create temporary vector to hold merged subvectors
   vector<T> temp(high - low + 1);

   int i = low;      // Subscript for start of left sorted subvector
   int j = mid+1;    // Subscript for start of right sorted subvector
   int k = 0;        // Subscript for start of merged vector

   // While not at the end of either subvector
   while (i <= mid && j <= high)
      {
	if (compare(set[j], set[i]))
         {
	   temp[k] = set[j];  // Copy element j of set into element k of temp
	   j++;  // Add one to j
           k++;  // Add one to k
         }
	else
         {
	   temp[k] = set[i];// Copy element i of set into element k of temp    	  
	   i++; // Add one to i	  
	   k++; // Add one to k
         }
      }

   // Copy over any remaining elements of left subvector
   while (i <= mid)
      {

	temp[k] = set[i];  // Copy element i of set into element k of temp
	i++; // Add one to i
	k++;  // Add one to k
      }

   // Copy over any remaining elements of right subvector
   while (j <= high)
      {
	
	temp[k] = set[j];  // Copy element j of set into element k of temp	      
	j++;  // Add one to j
	k++; //Add one to k
      }

   // Copy merged elements back into original vector
   for (i = 0, j = low; j <= high; i++, j++)
     set[j] = temp[i]; // Copy element i of temp into element j of set
}
#endif
