#ifndef PRACTICE_ALGORITHM_SORT_H
#define PRACTICE_ALGORITHM_SORT_H

#include <vector>

class Sort {
public:
    Sort() {};
    ~Sort() {};
    void QuickSort(std::vector<int> &vec);

private:
    void partionForQuickSort(std::vector<int> &vec, int begin, int end);
    void swap(int *a, int *b);
};

#endif