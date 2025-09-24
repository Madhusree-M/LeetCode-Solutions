//Problem: 153. Find Minimum in Rotated Sorted Array

/*
Given a rotated sorted array of unique elements, find the minimum element.
You must solve it in O(log n) time.

🔹 Example

Input:

nums = [3,4,5,1,2]


Output:

1

🔹 Code Explanation

Use binary search.
At each step, check if the left half is sorted (arr[low] <= arr[mid]):
If yes, the smallest element in this part is at arr[low]. Update mini.
Then move to the right half (low = mid + 1).
Otherwise, the right half is unsorted:
The minimum must lie here. Update mini = min(mini, arr[mid]).
Then move to the left half (high = mid - 1).
Continue until low > high.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

//Code :

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0 ,high = arr.size()-1;
        int mini = INT_MAX;
        while(low<=high)
        {
            int mid = (low+high)/2;
            //Left Sorted Array
            if(arr[low]<= arr[mid])
            {
                mini = min(mini,arr[low]);
                low = mid+1;
            }
            //Right Sorted Array
            else
            {
                mini = min(mini,arr[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};
