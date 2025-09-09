/*3477. Fruits Into Baskets II
  You are given two arrays fruits and baskets, each of length n.
  Each fruit type must be placed in the leftmost basket with enough capacity.
  Each basket can hold only one fruit type.
  If a fruit cannot be placed, it remains unplaced.
  Return the number of unplaced fruits.

Example
  Input: fruits = [4,2,5], baskets = [3,5,4]
  Output: 1

Explanation:
  4 → basket 5
  2 → basket 3
  5 → cannot fit in basket 4 → unplaced

🔹 Code Explanation
    Iterate over each fruit.
    For each fruit, scan baskets left to right.
    Place it in the first available basket with enough capacity, then mark that basket as used (-1).
    If no basket is found, increment the unplaced counter.*/

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        int n = fruits.size();
        for(int i = 0; i < n; i++) {
            int j;
            for(j = 0; j < n; j++) {
                if(baskets[j] != -1 && baskets[j] >= fruits[i]) {
                    baskets[j] = -1;  // mark basket as used
                    break;
                }
            }
            if(j == n) unplaced++;  // fruit not placed
        }
        return unplaced;
    }
};
