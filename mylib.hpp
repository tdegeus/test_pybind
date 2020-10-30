
#ifndef MYLIB_H
#define MYLIB_H

#include "xtensor.hpp"

namespace mylib {

template <class T>
inline auto myfunc(
    const std::vector<size_t>& roi,
    const T& w,
    const T& f,
    bool periodic = true)
{
    using value_type = typename T::value_type;

    xt::xarray<double> A = xt::zeros<double>(w.shape());
    return A;
}

template <class T, class M, class = typename std::enable_if_t<xt::has_iterator_interface<M>::value>>
inline auto myfunc(
    const std::vector<size_t>& roi,
    const T& w,
    const T& f,
    const M& fmask,
    bool periodic = true)
{
    using value_type = typename T::value_type;
    using mask_type = typename M::value_type;

    xt::xarray<double> A = xt::ones<double>(w.shape());
    return A;
}

} // namespace mylib

#endif
