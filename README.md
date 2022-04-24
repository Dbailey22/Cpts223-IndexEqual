# IndexEqual
1. Implement the efficient recursive version of the IndexEqual(A,i,j) algorithm described in 
Homework 1. This function should be initially called with i=0 and j=99. 
 
2. Implement an iterative version of IndexEqual(A,i,j) that loops through each of the elements 
from A[i] to A[j] looking for an entry such that A[k]=k. Your implementation should exit the 
loop upon finding such an element. This function should always be called with i=0 and j=99. 
 
3. As an estimate of the running time, you should record the number of comparisons between A[k] 
and k performed in each algorithm, where a comparison is any of ==, !=, <, >, <= or >=. You may 
use a global variable to do this. 
 
4. Your main function should evaluate your two algorithms using 100 different arrays, each of size 
100. The kth array will set A[k] = k and set the remaining elements to values not equal to their index. 
Remember that all the elements of the array must be unique integers and sorted in increasing order. 
You can store negative integers in the array. For each array you should output the number of the 
array (k) and the number of comparisons performed by each of the two algorithms on that array. At 
the end, you should also output the total number of comparisons performed by each algorithm over 
all 100 arrays.
