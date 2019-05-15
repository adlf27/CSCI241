#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <algorithm>

using std::swap;
using std::vector;

/****************************Function Prototype*****************************/
template <class T>
void quickSort(vector<T>&, bool (*compare)(const T&, const T&));

template <class T>
void quickSort(vector<T>&, int, int, bool (*compare)(const T&, const T&));

template <class T>
int partition(vector<T>&, int, int, bool (*compare)(const T&, const T&));


/********************************************************************
quickSort()
Use:calls the quicksort function
Parameters:reference to vector object, pointer to a comparison function
Returns:nothing
**********************************************************************/

template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
  quickSort(set, 0, set.size()-1, compare);
}

/********************************************************************
quickSort()
Use:this function performs the recursive calls to 
implement the quick sort algorithm
Parameters:reference to vector object, pointer to a comparison function
Returns:nothing
**********************************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
   int pivotPoint;

   if (start < end)
      {
	//Partition the vector and get the pivot point
	pivotPoint = partition(set, start, end, compare);

	//Sort the portion before the pivot point
	quickSort(set, start, pivotPoint - 1, compare);

	//Sort the portion after the pivot point
	quickSort(set, pivotPoint + 1, end, compare);
      }
}

/********************************************************************
partition()
Use:This function selects a pivot element and 
then partitions the vector around the pivot
Parameters:reference to vector object, pointer to a comparison function
integer start of vector and an integer end of vector
Returns:an integer 
**********************************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
  int pivotIndex, mid;
   T pivotValue;
   
   mid = (start + end) / 2;

   // Swap elements start and mid of the vector
   swap(set[start],set[mid]);
 
   pivotIndex = start;
   pivotValue = set[start];
 
   for (int scan = start + 1; scan <= end; scan++)
      {
      if (compare(set[scan], pivotValue))
         {
	   pivotIndex++;
	 //  Swap elements pivotIndex and scan of the vector
	   swap(set[pivotIndex + 1], set[scan]);
	   swap(set[pivotIndex], set[pivotIndex + 1]);
	 }
      }

   // Swap elements start and pivotIndex of the vector
   swap(set[start], set[pivotIndex]);

   return pivotIndex; 
}
#endif 
