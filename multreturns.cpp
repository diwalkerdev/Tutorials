#include <array>
#include <span>
#include <stdio.h>

// Multiple return types using if constexpr
// ----------------------------------------
// Code:
// https://github.com/diwalkerdev/Tutorials
// Notes:
// 1 - floating point / arithmetic concept
// 2 - operator [] using span.
// 3 - operator [] for vectors.

//////////////////////////////////////////////////////////////////////////////

template <std::floating_point Tp, std::size_t M, std::size_t N>
struct Matrix {
    using value_type = Tp;
    using reference  = value_type&;
    using size_type  = std::size_t;

    // TODO: redundancy, both matrix and array store size parameter.
    std::array<Tp, M * N> _elems;

    auto operator[](size_type pos)
    {
        if constexpr (N == 1)
        {
            return _elems[pos];
        }
        else if constexpr (M == 1)
        {
            return _elems[pos];
        }
        else
        {
            return std::span<float, N> {&_elems[pos * N], N};
        }
    }
};

//////////////////////////////////////////////////////////////////////////////

int main()
{
    Matrix<float, 2, 2> A;

    // Lazy, will improve on this later.
    A._elems = {1, 2, 3, 4};

    printf("%f\n", A[0][1]);

    Matrix<float, 1, 4> B;
    B._elems = {5, 6, 7, 8};

    printf("%f\n", B[0]);

    return 0;
}