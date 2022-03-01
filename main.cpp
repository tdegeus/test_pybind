#include <xtensor/xtensor.hpp>
#include <xtensor/xsort.hpp>

template <class T>
std::vector<size_t> myfunc(const T& scale)
{
    auto index = xt::unravel_index(xt::argmin(xt::abs(scale))(), scale.shape());
    size_t e = index[0];
    size_t q = index[1];
    return std::vector<size_t>{e, q};
}

int main()
{
    xt::xtensor<double, 2> A = {
        {1, 1, 2, 4, 5},
        {3, 4, 0.5, 6, 7},
        {1, 1, 2, 4, 5}
    };
    auto index = myfunc(A);

    if (index[0] != 1 || index[1] != 2) {
        throw std::runtime_error("Something went wrong");
    }
}
