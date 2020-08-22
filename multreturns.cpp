#include <array>
#include <stdio.h>

// Multiple return types using if constexpr
// ----------------------------------------
// Notes:
// 1 - floating point / arithmetic concept
// 2 - operator [] using span.
// 3 - operator [] for vectors.

//////////////////////////////////////////////////////////////////////////////

template <typename Tp, std::size_t M, std::size_t N>
struct Matrix {
    using value_type = Tp;
    using reference  = value_type&;
    using size_type  = std::size_t;

    // TODO: redundancy, both matrix and array store size parameter.
    std::array<Tp, M * N> _elems;

    auto operator[](size_type pos) -> reference
    {
        return _elems[pos];
    }
};

//////////////////////////////////////////////////////////////////////////////

int main()
{
    Matrix<float, 2, 2> A;

    // Lazy, will improve on this later.
    A._elems = {1, 2, 3, 4};

    printf("%f\n", A[0]);

    return 0;
}