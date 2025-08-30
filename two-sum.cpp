#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; // To store the complement of the current number and its index
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        // If complement is found, return the pair of indices
        if (num_map.find(complement) != num_map.end()) {
            result.push_back(num_map[complement]);
            result.push_back(i);
            return result;
        }

        // Store the index of the current number
        num_map[nums[i]] = i;
    }

    return result; // Return empty if no solution (although the problem guarantees one solution)
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "Output: [" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}
