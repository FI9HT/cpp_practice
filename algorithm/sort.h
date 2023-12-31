#ifndef PRACTICE_ALGORITHM_SORT_H
#define PRACTICE_ALGORITHM_SORT_H

#include <vector>

class Sort {
public:
    Sort() {};
    ~Sort() {};
    void quickSort(std::vector<int> &vec);
    void bubblingSort(std::vector<int> &vec);
    void mergeSort(std::vector<int> &vec);
private:
    void partionForQuickSort(std::vector<int> &vec, int begin, int end);
    void mergeSort(std::vector<int> &vec, int begin, int end);
    std::vector<int> mergeForMergeSort(std::vector<int> &vec, int begin, int mid, int end);
    void swap(int *a, int *b);
};

#endif