// To solve this challenge you can think that you have the highest value at hand.
// if the lowest value can't add to be lower than k, we need the second highest value then.
// This is because adding any higher value to the highest value won't make it smaller and closer to K.
// From that, you can think of having two pointers, (i,j), i > j.
// With the array sorted, you can move the pointers from lowest to highest numbers.

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i = 0, j = A.size() - 1;
        int maxValue = -1;
        while (i < j) {
            int curValue = A[i] + A[j];
            if (curValue < K) {
                maxValue = max(maxValue, curValue);
                i++;
            } else {
                j--;
            }
        }
        return maxValue;
    }
};