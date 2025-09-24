//290. Word Pattern


/*You are given a pattern string and a string s of space-separated words.
Check if s follows the same pattern:
Each letter in pattern maps to one unique word.
Each word maps back to exactly one unique letter.
No two letters map to the same word, and no two words map to the same letter.

🔹 Example 1

Input
pattern = "abba", s = "dog cat cat dog"

Output
true

🔹 Example 2
Input
pattern = "abba", s = "dog cat cat fish"


Output
false

🔹 Example 3

Input
pattern = "aaaa", s = "dog cat cat dog"

Output
false

🔹 Code Explanation

First split s into words (parts).
If the number of words is not equal to the length of the pattern → return false.
Use a HashMap<Character, String> to store the mapping from pattern characters to words.
For each character and word pair:
If neither character nor word exists → add mapping.
If character exists → check it maps to the same word, else return false.
If word exists but maps to another character → return false.
If the loop ends without conflicts → return true.

⏱ Time Complexity: O(n)
📦 Space Complexity: O(n)
*/

    
🔹 Code (java)

    class Solution {
    public boolean wordPattern(String pattern, String s) {
        String [] parts = s.split(" ");

        //If size not equal return false
        if(parts.length != pattern.length()) 
            return false;


        Map<Character,String> m = new HashMap<>();
        for(int i=0; i<pattern.length(); i++)
        {
            char ch = pattern.charAt(i);
            //If both not exists add it to map
            if(! m.containsKey(ch) && ! m.containsValue(parts[i]))
            {
                m.put(ch,parts[i]);
            }
            //If key exists in map -> then compare m[ch] with parts[i]
            else if(m.containsKey(ch))
            {
                if(! m.get(ch).equals(parts[i])) return false;
            }
            //Else If value exists and key not exists in map -> then return false
            else if(m.containsValue(parts[i]))
            {
                return false;
            }
        }
        return true;
    }
}
