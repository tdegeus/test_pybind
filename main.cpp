#include <xtensor/xtensor.hpp>
#include <xtensor/xsort.hpp>

int main()
{
    xt::xtensor<double, 2> A = {{0, 1, 2}, {3, -1, 4}};
    auto index = xt::unravel_index(xt::argmin(xt::abs(A))(), A.shape());
    size_t r = index[0];
    size_t c = index[1];
    assert(r == 1);
    assert(c == 1);
}
