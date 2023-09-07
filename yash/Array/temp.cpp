#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(vector<int>& nums) {
    int maxSum = nums[0]; // Initialize maxSum with the first element
    int currentSum = nums[0]; // Initialize currentSum with the first element

    // Loop through the array starting from the second element
    for (int i = 1; i < nums.size(); i++) {
        // Choose the larger of the current element and the sum of the current element and currentSum
        currentSum = max(nums[i], currentSum + nums[i]);
        
        // Update maxSum if the currentSum is greater
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    // Example usage
    vector<int> arr = {-7, -8, -16, -4, -8, -5, -7, -11, -10, -12, -4, -6, -4, -16, -10};
    int result = maxSubarraySum(arr);
    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}
