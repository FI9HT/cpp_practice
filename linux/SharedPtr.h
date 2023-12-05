#ifndef PRACTICE_LINUX_SHAREDPTR_H
#define PRACTICE_LINUX_SHAREDPTR_H

template <typename T>
class SharedPtr {
public:
    SharedPtr() : t_(nullptr), useCount_(new uint32_t(1)) {
        t_ = new T();
    }

    ~SharedPtr() {
        if (--(*useCount_) == 0) {
            delete t_;
            delete useCount_;
        }
    }

    SharedPtr(const SharedPtr<T> &ptr) {
        t_ = ptr.t_;
        useCount_ = ptr.useCount_;
        (*useCount_)++;
    }    

    SharedPtr<T>& operator=(const SharedPtr<T> &ptr) {
        if (this == &ptr) {
            return *this;
        }
        // 释放原来的对象
        if (t_) {
            if (--(*useCount_) == 0) {
                delete t_;
                delete useCount_;
            }            
        }
        // 转移权限
        t_ = ptr.t_;
        useCount_ = ptr.useCount_;
        (*useCount_)++;

        return *this;
    }

    SharedPtr(SharedPtr&& ptr) {
        t_ = ptr.t_;
        useCount_ = ptr.useCount_;
        (*useCount_)++;
    }    

    SharedPtr<T>& operator=(SharedPtr<T>&& ptr) {
        if (t_) {
            if (--(*useCount_) == 0) {
                delete t_;
                delete useCount_;
            }
        }
        t_ = ptr.t_;
        useCount_ = ptr.useCount_;
        (*useCount_)++;

        return *this;
    }

    T *operator->() {
        return t_;
    }

    T *get() {
        return t_;
    }

    T& operator*() {    // 注意返回类型是引用
        return *t_;
    }

    uint32_t *getUseCount() {
        return useCount_;
    }

private:
    T *t_;
    uint32_t *useCount_;
};


#endif