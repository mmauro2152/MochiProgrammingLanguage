#pragma once

template <typename T>
struct proxyarr {
    T* arr;

    T& operator[](int col) {
        return arr[col];
    }

    template <typename enum_>
    T& operator[](enum_ col) {
        return arr[static_cast<int>(col)];
    }

    bool isnull() {
        return arr == nullptr;
    }

    proxyarr(): arr(nullptr) {}
    proxyarr(T* r): arr(r) {}
    proxyarr(int len): arr(new T[len]) {}

};