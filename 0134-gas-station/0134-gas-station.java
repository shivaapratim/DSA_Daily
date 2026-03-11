class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {

        int gasSum = 0;
        int costSum = 0;

        for(int i = 0; i < gas.length; i++){
            gasSum += gas[i];
            costSum += cost[i];
        }

        if(gasSum < costSum) return -1;

        int bestIndex = 0;
        int sum = 0;

        for(int i = 0; i < gas.length; i++){
            sum += gas[i] - cost[i];
            if(sum < 0){
                bestIndex = i + 1;
                sum = 0;
            }
        }

        return bestIndex;
    }
}