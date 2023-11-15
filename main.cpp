#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <vector>
#include <functional>

#include "algorithm/sort.h"

using namespace std;

int main()
{
    Sort s;
    vector<int> v {9, 9, 8, 8, 5, 5, 3, 4, 2, 2, 2, 1, 1, 1, 2, 4};
    s.QuickSort(v);

    for (const auto &a : v) {
        cout << a;
    }
    cout << endl;

    return 0;
}