/// 754: https://leetcode.com/problems/reach-a-number/

class Solution {
public:
    int reachNumber(int target) {
        int solveEquation = ceil((-1 + sqrt(1+8.0*abs(target)))/2.0);
        int totalSum = solveEquation * (solveEquation + 1)/2;
        int jump = solveEquation;
        if ((totalSum - target)%2 != 0) {
            if ((jump+1)%2 == 0) jump += 2;
            else jump += 1;
        }
        return jump;
    }
};