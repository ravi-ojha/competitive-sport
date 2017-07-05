// A recursive solution for subset sum problem
#include <stdio.h>

// Returns true if there is a subset of set[] with sum equal to given reqsum
bool isSubsetSum(int set[], int n, int sum, int arrsize, int reqsum)
{
   // Base Cases
   if (sum == reqsum)
     return true;
   if (n == arrsize && sum != reqsum)
     return false;

   // If last element is greater than sum, then ignore it
//   if (set[n] > sum)
//     return isSubsetSum(set, n-1, sum);

   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element   */
   return isSubsetSum(set, n+1, sum, arrsize, reqsum) || isSubsetSum(set, n+1, sum+set[n], arrsize, reqsum);
}

// Driver program to test above function
int main()
{
  int set[] = {-2,-3,-5};
  int sum = -7;
  int n = sizeof(set)/sizeof(set[0]);
  if (isSubsetSum(set, 0, 0,n,sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}
