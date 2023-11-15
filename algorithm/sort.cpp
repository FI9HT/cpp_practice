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
    mergeSortReal(vec, 0, vec.size() - 1);
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

void Sort::mergeSortReal(std::vector<int> &vec, int begin, int end)
{
    if (begin >= end) return;
    int mid = (begin + end) / 2;
    mergeSortReal(vec, begin, mid);
    mergeSortReal(vec, mid + 1, end);
    std::vector<int> v1(vec.begin()+begin, vec.begin()+mid+1);
    std::vector<int> v2(vec.begin()+mid+1, vec.begin()+1+end);
    auto tmpVec = mergeForMergeSort(v1, v2);
    for (int i = 0; i < tmpVec.size(); i++) {
        vec[begin+i] = tmpVec[i];
    }
    for (auto a : vec) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

std::vector<int> Sort::mergeForMergeSort(std::vector<int> &v1, std::vector<int> &v2)
{
    std::cout << std::endl;
    std::vector<int> result;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j]) {
            result.push_back(v1[i++]);
        } else {
            result.push_back(v1[j++]);
        }
    }
    if (i < v1.size()) {
        result.insert(result.end(), v1.begin()+i, v1.end());
    } else {
        result.insert(result.end(), v2.begin()+j, v2.end());
    }

    std::cout << "v1: ";
    for (auto a : v1) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    std::cout << "v2: ";
    for (auto a : v2) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    std::cout << "v3: ";
    for (auto a : result) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return result;
}

void Sort::swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
