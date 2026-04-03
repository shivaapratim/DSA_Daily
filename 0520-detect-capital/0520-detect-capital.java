class Solution {
    public boolean detectCapitalUse(String word) {
        String upperWord=word.toUpperCase();
        String lower = word.toLowerCase();
        String onecap= word.substring(0,1).toUpperCase()+word.substring(1).toLowerCase();
        
        if(word.equals(upperWord)){
            return true;
        }
        else if(word.equals(lower)){
            return true;
        }
        else if(word.equals(onecap)){
            return true;
        }
       return false;
    }
}