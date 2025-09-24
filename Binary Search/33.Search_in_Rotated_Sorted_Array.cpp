//Problem: 33. Search in Rotated Sorted Array

/*Brief:
You are given an integer array nums sorted in ascending order, but rotated at some pivot index. You are also given an integer target. Return the index of target if it exists, otherwise return -1.

🔹 Example

Input:
nums = [4,5,6,7,0,1,2], target = 0

Output:
4

🔹 Code Explanation

Use modified binary search.
At each step, one half of the array is guaranteed to be sorted.
If arr[low] <= arr[mid], then the left half is sorted:
Check if target lies in this left half.
If yes → move high = mid - 1, else search right half.
Otherwise, the right half is sorted:
Check if target lies in this right half.
If yes → move low = mid + 1, else search left half.
Continue until low > high.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;

            if(arr[mid] == target) return mid;

            // Search in left sorted half
            if(arr[low] <= arr[mid]) {
                if(arr[low] <= target && target <= arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Search in right sorted half
            else {
                if(arr[mid] <= target && target <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
