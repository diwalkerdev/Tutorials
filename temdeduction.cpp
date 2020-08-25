#include <array>
#include <iostream>
#include <tuple>

template <typename Tp, std::size_t Size>
struct Data {
    std::array<Tp, Size> _elems;
};

template <class _Tp, class... _Args, class = std::enable_if_t<std::conjunction_v<std::is_same<_Tp, _Args>...>>>
Data(_Tp, _Args...) -> Data<_Tp, 1 + sizeof...(_Args)>;

//////////////////////////////////////////////////////////////////////////////

template <typename... Args>
struct MyTuple {
    std::tuple<Args...> values;

    MyTuple(Args... args)
        : values(args...)
    {
    }
};

template <class... Tps>
MyTuple(Tps...) -> MyTuple<Tps...>;

//////////////////////////////////////////////////////////////////////////////

auto main() -> int
{
    // List initializer vs aggregate initializer.
    auto x = {1, 2, 3};


    std::array data {false, false, true};
    //std::array more_data {{"hello", false}, {"goodbye", false}, {"maybe", true}};
    Data more_data {std::tuple {"hello", false, 1},
                    std::tuple {"goodbye", false, 2},
                    std::tuple {"maybe", true, 3},
                    std::tuple {"maybe", true, 4}};

    MyTuple t {1, "hello"};
    std::cout << std::get<0>(t.values) << "  " << std::get<1>(t.values) << "\n";

    for (auto d : more_data._elems)
    {
        std::cout << std::get<0>(d) << "  " << std::get<1>(d) << "\n";
    }

    return 0;
}