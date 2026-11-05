#include "../include/SearchAlgorithms.h"

int binarySearchLowerBound(const std::vector<Registro>& arr, int64_t targetTimestamp) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;
    int ans = static_cast<int>(arr.size());

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].timestamp >= targetTimestamp) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int binarySearchUpperBound(const std::vector<Registro>& arr, int64_t targetTimestamp) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].timestamp <= targetTimestamp) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}