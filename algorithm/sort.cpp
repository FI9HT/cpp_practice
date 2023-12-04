#include "sort.h"

#include <iostream>

void Sort::quickSort(std::vector<int> &vec)
{
    partionForQuickSort(vec, 0, vec.size() - 1);
}

void Sort::bubblingSort(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = vec.size() - 1; j > i; j--) {
            if (vec[j] < vec[j-1]) {
                swap(&vec[j], &vec[j-1]);
            }
        }
    }
}

void Sort::mergeSort(std::vector<int> &vec)
{
    mergeSort(vec, 0, vec.size() - 1);
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

void Sort::mergeSort(std::vector<int> &vec, int begin, int end)
{
    if (begin >= end) return;
    int mid = (begin + end) / 2;
    mergeSort(vec, begin, mid);
    mergeSort(vec, mid + 1, end);
    
    std::vector<int> tmpVec = mergeForMergeSort(vec, begin, mid, end);

    for (int i = 0; i < tmpVec.size(); i++) {
        vec[begin+i] = tmpVec[i];
    }
}

std::vector<int> Sort::mergeForMergeSort(std::vector<int> &vec, int begin, int mid, int end)
{
    std::vector<int> result;
    
    int i = begin, j = mid+1;
    while (i <= mid && j <= end) {
        if (vec[i] < vec[j]) {
            result.push_back(vec[i++]);
        } else {
            result.push_back(vec[j++]);
        }
    }

    if (i <= mid) {
        result.insert(result.end(), vec.begin()+i, vec.begin()+mid+1);
    } else {
        result.insert(result.end(), vec.begin()+j, vec.begin()+end+1);
    }

    return result;
}

void Sort::swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
