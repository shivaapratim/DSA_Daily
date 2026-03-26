import java.util.*;

class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length;         
        int m = matrix[0].length;     

        HashSet<Integer> rows = new HashSet<>();
        HashSet<Integer> cols = new HashSet<>();

        // store rows & cols having 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    rows.add(i);
                    cols.add(j);
                }
            }
        }

        // update matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rows.contains(i) || cols.contains(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
}