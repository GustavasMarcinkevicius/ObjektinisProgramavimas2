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
    T* new_data = static_cast<T*>(operator new[](new_cap * sizeof(T)));
    for (size_t i = 0; i < sz; ++i) {
        new (&new_data[i]) T(std::move(data[i]));
        data[i].~T();
    }
    operator delete[](data);
    data = new_data;
    cap = new_cap;
}

public:
    //MEMBER TYPES
     using value_type             = T;
    using size_type              = std::size_t;
    using difference_type        = std::ptrdiff_t;
    using reference              = T&;
    using const_reference        = const T&;
    using pointer                = T*;
    using const_pointer          = const T*;
    using iterator               = T*;
    using const_iterator         = const T*;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // ITERATOR VALIDATION
    void swap(ManoVektorius& other) {
        std::swap(data, other.data);
        std::swap(sz, other.sz);
        std::swap(cap, other.cap);
}
    void clear() {
    for (size_t i = 0; i < sz; ++i) {
        data[i].~T();
    }
    sz = 0;
}

    void reserve(size_t new_cap) {
        if (new_cap > cap)
            reallocate(new_cap);
    }
void erase(size_t index) {
    if (index >= sz) throw std::out_of_range("Nera tokio elemento trinimui!");
    data[index].~T();
    for (size_t i = index; i < sz - 1; ++i) {
        new (&data[i]) T(std::move(data[i + 1]));
        data[i + 1].~T();
    }
    --sz;
}
void push_back(const T& value) {
    if (sz >= cap) {
        reallocate(cap == 0 ? 1 : cap * 2);
    }
    new (&data[sz]) T(value);
    ++sz;
}

    void insert(size_t index, const T& value) {
    if (index > sz) throw std::out_of_range("Insert pozicija negalima");
    if (sz >= cap) reallocate(cap == 0 ? 1 : cap * 2);
    for (size_t i = sz; i > index; --i)
        data[i] = data[i - 1];
    data[index] = value;
    ++sz;
}
    void resize(size_t new_size, const T& default_value = T()) {
        reserve(new_size);
        for (size_t i = sz; i < new_size; ++i)
            data[i] = default_value;
        sz = new_size;
    }    
void pop_back() {
    if (sz > 0) {
        --sz;
        data[sz].~T();
    }
}
//------------------------------------------------------------------------
// MEMBER FUNCTIONS
    // Constructor
    ManoVektorius() : data(nullptr), sz(0), cap(0) {}

    // Destructor
~ManoVektorius() {
    for (size_t i = 0; i < sz; ++i) {
        data[i].~T();
    }
    operator delete[](data);
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
ManoVektorius& operator=(const ManoVektorius& other) { //Operator=
    if (this != &other) {
        delete[] data;
        sz = other.sz;
        cap = other.cap;
        data = new T[cap];
        for (size_t i = 0; i < sz; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

void assign(size_t count, const T& value) {
    if (count > cap)
        reallocate(count);
    for (size_t i = 0; i < count; ++i)
        data[i] = value;
    sz = count;
}
template<typename InputIt>
void assign_range(InputIt first, InputIt last) {
    size_t count = std::distance(first, last);
    if (count > cap)
        reallocate(count);
    clear(); // destroy old elements, sz=0
    for (; first != last; ++first)
        emplace_back(*first);
}
std::allocator<T> get_allocator() const {
    return std::allocator<T>();
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


    //ELEMENT ACCESS
// Access element with bounds checking
T& at(size_t pos) {
    if (pos >= sz)
        throw std::out_of_range("Indekso nera");
    return data[pos];
}

// Access element 
T& operator[](size_t pos) {
    return data[pos];   
}

// Access first element
T& front() {
    return data[0];
}

// Access last element 
T& back() {
    return data[sz - 1];
}


// Get pointer to underlying array 
T* data() {
    return data;
}

const T& at(size_t pos) const {
    if (pos >= sz)
        throw std::out_of_range("Indeksas neteisingas");
    return data[pos];
}

const T& operator[](size_t pos) const {
    return data[pos];
}

const T& front() const {
    return data[0];
}

const T& back() const {
    return data[sz - 1];
}

const T* data_() const {
    return data;
}

//CAPACITY
bool empty() const {
    return sz == 0;
}
size_t size() const {
    return sz;
}
size_t max_size() const {
    return std::numeric_limits<size_t>::max() / sizeof(T);
}
size_t capacity() const {
    return cap;
}
void shrink_to_fit() {
    if (cap > sz) {
        reallocate(sz);
    }
}
//MODIFIERS
template <typename... Args>
void emplace_back(Args&&... args) {
    if (sz >= cap) {
        reallocate(cap == 0 ? 1 : cap * 2);
    }
    new(&data[sz]) T(std::forward<Args>(args)...);  // placement new
    ++sz;
}
template <typename InputIt>
void append_range(InputIt first, InputIt last) {
    size_t range_size = std::distance(first, last);
    reserve(sz + range_size); // Ensure capacity

    for (; first != last; ++first) {
        new (&data[sz]) T(*first);  // Construct element in place
        ++sz;
    }
}
template <typename... Args>
void emplace(size_t index, Args&&... args) {
    if (index > sz)
        throw std::out_of_range("Negalima insert pozicija");
    if (sz >= cap)
        reallocate(cap == 0 ? 1 : cap * 2);

    for (size_t i = sz; i > index; --i)
        data[i] = data[i - 1];

    new (&data[index]) T(std::forward<Args>(args)...);
    ++sz;
}

};

#endif // MANOVEKTORIUS_HPP
