#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
using std::vector;
using std::cout;
using std::endl;
//using std::tab
int comparisons_recursive = 0;
int comparisons_iterative = 0;
int r_counter = 0;
int i_counter = 0;
/*
Function: Recursive function that loops through each elements of the array looking for an entry such at A[i] = i
*/

//This is the efficient recursive function 
//Wants the function to be initially called with i = 0 and j =99 so I set the values to that
//I will be referencing the solution I didn't realize we could ignore half the array each time we traverse the array
//I will be calling this function and iterative solution in main
bool IndexEqual_recursive(vector<int> &A, int i, int j)
{
    if (i <= j)
    {
        int k = ((i+j) /2);
        if(A[k] == k)
        {
            comparisons_recursive+= 1;
            r_counter+= 1;
            return true;
        }
        if (A[k] < k)
        {
            comparisons_recursive += 2;
            r_counter += 2;
            return IndexEqual_recursive(A, k+1, j);
        }
        else if (A[k] > k)
        {
            comparisons_recursive += 3;
            r_counter += 3;
            return IndexEqual_recursive(A, i, k-1);
        }
    }
    else 
    {
        return false;
    }
}
/*
Function: Iterative function that loops through each elements of the array looking for an entry such at A[i] = i
*/
//This is the iterative version of the IndexEqual above

bool IndexEqual_iterative(vector<int> &A, int i, int j)
{   
    for (i; i <= j; i++)
    {   
        comparisons_iterative++;
        i_counter++;
        if (A[i] == i)
        {   
        return true;
        }

    //If i is in the array then it will return true
    }
    //if the index is not in any of the arrays then it will return false
    return false;
}

int main()
{   
    //I referenced this code to set the 100 arrays and the pushback function
        //-https://stackoverflow.com/questions/7131741/initializing-multiple-unique-entries-of-a-vector
    vector<vector<int>> A(100);
    //have to initialize 100 arrays
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (j ==i)
            {
                A[i].push_back(j);
                for (j; j < 100; j++)
                {
                    A[i].push_back(j+2);
                }
            }
            else A[i].push_back(j-1);
        }
    }
//arrays have been initialized, now im going to run the functions above and then print the results to the screen
for (int j = 0; j < 100; j++)
{   //The functions must be called with 0 and 99 in the paramaters
    IndexEqual_recursive(A[j], 0, 99);
    IndexEqual_iterative(A[j], 0 , 99);
    cout << '\t' << j << '\t' << r_counter << '\t' << i_counter << endl;
    //I'm getting completely different numbers than example
    //I have to set them back to 0 after the loop
    i_counter = 0;
    r_counter = 0;
}
cout << "Total recursive comparisons: " << comparisons_recursive << endl;
cout << "Total iterative comparisons: " << comparisons_iterative << endl;

}