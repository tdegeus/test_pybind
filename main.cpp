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
    xt::xtensor<double, 2> A = {{0, 1, 2}, {3, 4, -1}};
    auto index = myfunc(A);
    assert(index[0] == 1);
    assert(index[1] == 1);
}
