/*81. Search in Rotated Sorted Array II

You are given a rotated sorted array nums (possibly containing duplicates) and an integer target.
Return true if target exists in nums, otherwise false.
The goal is to minimize the number of operations.

🔹 Example 1
Input:
nums = [2,5,6,0,0,1,2], target = 0

Output:
true

🔹 Example 2
Input:
nums = [2,5,6,0,0,1,2], target = 3

Output:
false

🔹 Code Explanation

This is an extension of the rotated sorted array search (Problem 33), but with duplicates allowed.
Standard binary search is used with modifications:
If arr[mid] == target, return true.
If arr[low] == arr[mid] == arr[high], we can’t decide which half is sorted → shrink search space (low++, high--).
Otherwise, if left half is sorted (arr[low] <= arr[mid]):
Check if target lies in left half → adjust high.
Else → move low.
If right half is sorted:
Check if target lies in right half → adjust low.
Else → move high.
Continue until low > high.

Time Complexity: O(log n) in average case, but can degrade to O(n) in worst case (due to duplicates).
Space Complexity: O(1)
*/


//🔹 Code (C++)

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int low = 0, high =arr.size()-1;
        while(low<=high)
        {
            int mid = (low + high)/2;

            if(arr[mid]==target) return true;
            if(arr[low] == arr[high] && arr[low]==arr[mid])
            {
                low++;
                high--;
            }
            else if(arr[low]<= arr[mid])
            {
                if(arr[low]<=target && target<=arr[mid])
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            else
            {
                if(arr[mid]<=target && target<=arr[high])
                {
                    low = mid+1;
                }
                else

                high=mid-1;
            }
        }
        return false;
    }
};
