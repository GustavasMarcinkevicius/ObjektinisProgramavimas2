#include "Includes.h"

#ifndef MANOVEKTORIUS_HPP
#define MANOVEKTORIUS_HPP

#include <iostream>

template <typename T>
class ManoVektorius {
private:
    T* data;
    size_t sz;
    size_t cap;

    void reallocate(size_t new_cap) {
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < sz; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        cap = new_cap;
    }

public:
    // Constructor
    ManoVektorius() : data(nullptr), sz(0), cap(0) {}

    // Destructor
    ~ManoVektorius() {
        delete[] data;
    }

    // Copy constructor
    ManoVektorius(const ManoVektorius& other) {
        sz = other.sz;
        cap = other.cap;
        data = new T[cap];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment
    ManoVektorius& operator=(const ManoVektorius& other) {
        if (this != &other) {
            delete[] data;
            sz = other.sz;
            cap = other.cap;
            data = new T[cap];
            for (size_t i = 0; i < sz; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Move constructor
    ManoVektorius(ManoVektorius&& other) noexcept {
        data = other.data;
        sz = other.sz;
        cap = other.cap;
        other.data = nullptr;
        other.sz = other.cap = 0;
    }

    // Move assignment
    ManoVektorius& operator=(ManoVektorius&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            sz = other.sz;
            cap = other.cap;
            other.data = nullptr;
            other.sz = other.cap = 0;
        }
        return *this;
    }

    void push_back(const T& value) {
        if (sz >= cap) {
            reallocate(cap == 0 ? 1 : cap * 2);
        }
        data[sz++] = value;
    }

    void pop_back() {
        if (sz > 0) --sz;
    }

    size_t size() const { return sz; }
    size_t capacity() const { return cap; }
    bool empty() const { return sz == 0; }

    void clear() { sz = 0; }

    void reserve(size_t new_cap) {
        if (new_cap > cap)
            reallocate(new_cap);
    }

    void resize(size_t new_size, const T& default_value = T()) {
        reserve(new_size);
        for (size_t i = sz; i < new_size; ++i)
            data[i] = default_value;
        sz = new_size;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    T* begin() { return data; }
    T* end() { return data + sz; }
};

#endif // MANOVEKTORIUS_HPP
