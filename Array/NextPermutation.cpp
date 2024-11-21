//Using C++ in-built function
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = { 2,4,1,7,5,0 };
    next_permutation(arr.begin(), arr.end());
    for (int num : arr)
        cout << num << " ";
    return 0;
}
//2nd Approach
//[Expected Approach] Generating Only Next - O(n) Time and O(1) Space

void nextPermutation(vector<int>& arr) {
        //next_permutation(arr.begin(),arr.end());
         int index = -1;
        int n = arr.size();
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                index = i;
                break;
            }
        }

        // If no such index is found, the array is in descending order
        if (index == -1) {
            reverse(arr.begin(), arr.end()); // Reverse the entire array
            return;
        }

        // Find the smallest element that is greater than nums[index] to swap
        for (int i = n - 1; i > index; i--) {
            if (arr[i] > arr[index]) {
                swap(arr[i], arr[index]);  // Swap
                break;
            }
        }
            reverse(arr.begin() + index + 1, arr.end());
        
    }