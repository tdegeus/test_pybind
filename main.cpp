#include <vector>
#include <xtensor/xtensor.hpp>
#include <xtensor/xsort.hpp>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#define FORCE_IMPORT_ARRAY
#include <xtensor-python/pyarray.hpp>
#include <xtensor-python/pytensor.hpp>

namespace py = pybind11;

template <class T>
std::vector<size_t> myfunc(const T& scale)
{
    auto index = xt::unravel_index(xt::argmin(xt::abs(scale))(), scale.shape());
    size_t e = index[0];
    size_t q = index[1];
    return std::vector<size_t>{e, q};
}


PYBIND11_MODULE(mymodule, m)
{
    m.doc() = "Foo";
    xt::import_numpy();
    m.def("myfunc", &myfunc<xt::pytensor<double, 2>>, "myfunc");
}
