#include "sort.h"

#include <iostream>

void Sort::QuickSort(std::vector<int> &vec)
{
    partionForQuickSort(vec, 0, vec.size() - 1);
}

void Sort::partionForQuickSort(std::vector<int> &vec, int begin, int end)
{
    if (begin >= end) return;   // 这里要大于等于，因为上一轮中，l有可能等于begin，如3，2，1这样的逆序

    int soldier = vec[begin];
    int l = begin, r = end;
    while (l < r) {
        while (r > l && vec[r] >= soldier) r--;
        while (l < r && vec[l] <= soldier) l++;
        if (l < r) {
            swap(&vec[l], &vec[r]);
        }
    }
    swap(&vec[begin], &vec[l]);
    partionForQuickSort(vec, begin, l - 1);
    partionForQuickSort(vec, l + 1, end);
}

void Sort::swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
