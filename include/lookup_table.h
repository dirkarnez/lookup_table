#pragma once

#ifdef _WINDLL
#define WIN_EXPORT __declspec(dllexport)
#else
#define WIN_EXPORT
#endif
//
//template<int N>
//struct ArrayWrapper {
//    /*constexpr ArrayWrapper() : array() {
//        for (auto i = 0; i < N; i++)
//            array[i] = i; 
//    }*/
//    constexpr int array[N];
//};


#include <array>

enum Type {
    Alphabet,
    Number,
    Symbol,
    Other,
};

constexpr ::std::array<Type, 128> MagicFunction()
{
    using result_t = ::std::array<Type, 128>;
    result_t result = { Other };
    const result_t& fake_const_result = result;
    const_cast<result_t::reference>(fake_const_result[65]) = Alphabet;
    //....
    return result;
}

template<class T, class ... Rest>
void g(T&& p, Rest &&...rs)
{
    // ... handle p
    if constexpr (sizeof...(rs) > 0)
        g(rs...);  // never instantiated with an empty argument list
}


template <int I>
struct squared {
    squared<I - 1> rest;
    static const int x = I * I;
    constexpr int operator[](int const& i) const { return (i == I ? x : rest[i]); }
    constexpr int size() const { return I; }
};
template <>
struct squared<0> {
    static const int x = 0;
    constexpr int operator[](int const& i) const { return x; }
    constexpr int size() const { return 1; }
};


extern "C" WIN_EXPORT
void GetRandomNumberArrayOfLength10(int* arr)
{
    squared<10> squared;

    static_assert(squared[0] == 0, "");

    //constexpr static auto length = 10;
    //constexpr static auto array = ArrayWrapper<length>::array;

    const ::std::array<Type, 128> table = MagicFunction();


    //static_assert(table[0][0] == Other, "???");
    //for (auto i = 0; i < length; i++)
    //    arr[i] = array[i];
}