/*1399. Count Largest Group
  Group numbers 1 to n based on the sum of their digits. Return how many groups have the maximum size.

🔹 Example
  Input: n = 13
  Output : 4

Explanation:
Groups → [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
Largest size = 2 → 4 groups.

🔹 Code Explanation
    Write a helper sumof() to compute digit sum.
    Use a hash map to count how many numbers fall into each digit-sum group.
    Track the largest group size while filling the map.
    Finally, count how many groups match this largest size.*/

class Solution {
public:
    int sumof(int n) {
        int sum = 0;
        while(n != 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        int maxi = 0;
        unordered_map<int, int> m;  
        for(int i = 1; i <= n; i++) {
            int sum = sumof(i);
            m[sum]++;
            maxi = max(maxi, m[sum]);
        }
        int count = 0;
        for(auto &it : m) {
            if(it.second == maxi) count++;
        }
        return count;
    }
};
