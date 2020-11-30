#pragma once

#ifdef _WINDLL
#define WIN_EXPORT __declspec(dllexport)
#else
#define WIN_EXPORT
#endif

template<int N>
struct ArrayWrapper {
    constexpr ArrayWrapper() : array() {
        for (auto i = 0; i < N; i++)
            array[i] = i; 
    }
    int array[N];
};

extern "C" WIN_EXPORT
void GetRandomNumberArrayOfLength10(int* arr)
{
    constexpr auto length = 10;
    auto array = ArrayWrapper<length>().array;
    for (auto i = 0; i < length; i++)
        arr[i] = array[i];
}