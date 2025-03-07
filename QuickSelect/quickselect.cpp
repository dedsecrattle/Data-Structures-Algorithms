#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int> &nums, int left, int right);
int quickSelect(vector<int> &nums, int k);

int quickSelect(vector<int> &nums, int k)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int pivotIndex = partition(nums, left, right);
        if (pivotIndex == k)
        {
            return nums[k];
        }
        else if (pivotIndex < k)
        {
            left = pivotIndex + 1;
        }
        else
        {
            right = pivotIndex - 1;
        }
    }
    return -1;
}

int partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[right];
    int i = left;
    int j = right - 1;
    while (i <= j)
    {
        if (nums[i] < pivot)
        {
            i++;
        }
        else if (nums[j] >= pivot)
        {
            j--;
        }
        else
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    nums[right] = nums[i];
    nums[i] = pivot;
    return i;
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = quickSelect(nums, k);
    cout << result << endl;
    return 0;
}