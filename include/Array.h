#ifndef LAB04_ARRAY_H
#define LAB04_ARRAY_H

#include <memory>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;

    void resizeIfNeeded() {
        if (_size >= _capacity) {
            size_t new_cap = _capacity == 0 ? 1 : _capacity * 2;
            T* new_data = new T[new_cap];

            for (size_t i = 0; i < _size; ++i) {
                new_data[i] = std::move(data[i]);
            }

            delete[] data;
            data = new_data;
            _capacity = new_cap;
        }
    }

public:
    Array() = default;

    ~Array() {
        delete[] data;
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    void push_back(const T& item) {
        resizeIfNeeded();
        data[_size++] = item;
    }

    void push_back(T&& item) {
        resizeIfNeeded();
        data[_size++] = std::move(item);
    }

    void removeAt(size_t index) {
        if (index >= _size) throw std::out_of_range("за индексом");
        for (size_t i = index; i < _size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        --_size;
    }

    T& operator[](size_t index) {
        if (index >= _size) throw std::out_of_range("за индексом");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= _size) throw std::out_of_range("за индексом");
        return data[index];
    }

    size_t size() const { return _size; }
    bool empty() const { return _size == 0; }

    T* begin() { return data; }
    T* end() { return data + _size; }
    const T* begin() const { return data; }
    const T* end() const { return data + _size; }
};

#endif
