#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int randomIdx = left + rand() % (right - left + 1);
    swap(nums[randomIdx], nums[right]);
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (nums[j] >= pivot) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}

int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left == right) return nums[left];
    int pivotIndex = partition(nums, left, right);
    int rank = pivotIndex - left;
    if (rank == k) return nums[pivotIndex];
    else if (rank > k) return quickSelect(nums, left, pivotIndex - 1, k);
    else return quickSelect(nums, pivotIndex + 1, right, k - rank - 1);
}

int findKthLargest(vector<int>& nums, int k) {
    srand((unsigned)time(0));
    return quickSelect(nums, 0, (int)nums.size() - 1, k - 1);
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    if (!fin) {
        fout << "2024112541" << endl;
        fout << "Error: Cannot open in.txt" << endl;
        return 1;
    }

    vector<int> nums;
    int val;
    while (fin >> val) {
        nums.push_back(val);
    }
    fin.close();

    if (nums.empty()) {
        fout << "2024112541" << endl;
        fout << "Error: No numbers in in.txt" << endl;
        return 1;
    }

    int k = nums.back();
    nums.pop_back();

    if (k < 1 || k >(int)nums.size()) {
        fout << "2024112541" << endl;
        fout << "Error: k out of range" << endl;
        return 1;
    }

    int ans = findKthLargest(nums, k);

    fout << "2024112541" << endl;
    fout << ans << endl;
    fout.close();

    return 0;
}