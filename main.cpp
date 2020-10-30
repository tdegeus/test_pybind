
#include <pybind11/pybind11.h>
#include <pyxtensor/pyxtensor.hpp>

#include "mylib.hpp"

namespace py = pybind11;

PYBIND11_MODULE(mylib, m)
{

m.doc() = "...";

m.def("myfunc", py::overload_cast<
        const std::vector<size_t>&,
        const xt::xarray<int>&,
        const xt::xarray<int>&,
        bool>(&mylib::myfunc<xt::xarray<int>>),
    py::arg("roi"),
    py::arg("w"),
    py::arg("f"),
    py::arg("periodic") = true);

m.def("myfunc", py::overload_cast<
        const std::vector<size_t>&,
        const xt::xarray<double>&,
        const xt::xarray<double>&,
        bool>(&mylib::myfunc<xt::xarray<double>>),
    py::arg("roi"),
    py::arg("w"),
    py::arg("f"),
    py::arg("periodic") = true);

m.def("myfunc", py::overload_cast<
        const std::vector<size_t>&,
        const xt::xarray<double>&,
        const xt::xarray<double>&,
        const xt::xarray<int>&,
        bool>(&mylib::myfunc<xt::xarray<double>, xt::xarray<int>>),
    py::arg("roi"),
    py::arg("w"),
    py::arg("f"),
    py::arg("fmask"),
    py::arg("periodic") = true);

}
