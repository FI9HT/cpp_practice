#include <stdio.h>
#include <unistd.h>

#include <iostream>
#include <vector>
#include <functional>

#include "algorithm/sort.h"

using namespace std;

class A {
private:
    void out() {
        cout << "A->out()" << endl;
    }
};

class B {
public:
    void getFuncRun(function<void(void)> func) {
        func();
    }
};

int main()
{
    A a;
    B b;
    b.getFuncRun(bind(&A::out, &a));

    return 0;
}