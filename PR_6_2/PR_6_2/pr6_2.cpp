#include <iostream>
#include <vector>
#include <iomanip> // Äëÿ std::setw
#include <algorithm> // Äëÿ std::swap

void printArray(const std::vector<int>& arr) {
    std::cout << "[ ";
    for (int num : arr) {
        std::cout << std::setw(4) << num;
    }
    std::cout << " ]" << std::endl;
}

int findMinIndex(const std::vector<int>& arr) {
    if (arr.empty()) return -1;

    int minIdx = 0;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i;
        }
    }
    return minIdx;
}

int findMaxIndex(const std::vector<int>& arr) {
    if (arr.empty()) return -1;

    int maxIdx = 0;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

bool swapMinMax(std::vector<int>& arr) {
    int minIdx = findMinIndex(arr);
    int maxIdx = findMaxIndex(arr);

    if (minIdx == -1 || maxIdx == -1) {
        return false;
    }

    if (minIdx != maxIdx) {
        std::swap(arr[minIdx], arr[maxIdx]);
        return true;
    }

    return false;
}

int main() {
    std::vector<int> myArray = { 12, -5, 8, 24, 0, 24, -5, 7 };

    std::cout << "--- ITERATIVE METHOD ---" << std::endl;

    std::cout << "Original array: ";
    printArray(myArray);

    bool isChanged = swapMinMax(myArray);

    if (isChanged) {
        std::cout << "Modified array: ";
        printArray(myArray);
    }
    else {
        std::cout << "Array was not modified (min and max match or array empty)." << std::endl;
    }

    return 0;
}