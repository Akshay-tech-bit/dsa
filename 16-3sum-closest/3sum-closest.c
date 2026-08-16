int threeSumClosest(int* nums, int numsSize, int target) {
    
    // Sort the array
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            // Check if current sum is closer
            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
            }

            // Exact match
            if (sum == target) {
                return sum;
            }

            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return closest;
}