import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> ransomMap = new HashMap<>();
        Map<Character, Integer> magazineMap = new HashMap<>();

        // Fill ransomNote map
        for (char c : ransomNote.toCharArray()) {
            ransomMap.put(c, ransomMap.getOrDefault(c, 0) + 1);
        }

        // Fill magazine map
        for (char c : magazine.toCharArray()) {
            magazineMap.put(c, magazineMap.getOrDefault(c, 0) + 1);
        }

        // Check if ransomNote can be constructed
        for (Map.Entry<Character, Integer> entry : ransomMap.entrySet()) {
            char c = entry.getKey();
            int count = entry.getValue();

            if (magazineMap.getOrDefault(c, 0) < count) {
                return false; // Not enough letters
            }
        }

        return true; // All letters are available
    }
}