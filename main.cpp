#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <GooseFEM/GooseFEM.h>

namespace py = pybind11;

class Myclass
{
public:
    Myclass() = default;

    Myclass(size_t n) {
        m_mesh = GooseFEM::Mesh::Quad4::Regular(n, n);
        m_vector = GooseFEM::Vector(m_mesh.conn(), m_mesh.dofs());
    }

    const GooseFEM::Vector& vector() const
    {
        return m_vector;
    }

private:
    GooseFEM::Mesh::Quad4::Regular m_mesh;
    GooseFEM::Vector m_vector;
};


PYBIND11_MODULE(mymodule, m)
{
    m.doc() = "Foo";
    py::class_<Myclass> cls(m, "Myclass");
    cls.def(py::init<size_t>(), "Myclass", py::arg("n"));
    cls.def("vector", &Myclass::vector, "vector");
}
