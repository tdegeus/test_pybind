import FrictionQPotFEM.UniformSingleLayer2d as model
import GMatElastoPlasticQPot.Cartesian2d as GMat
import GooseFEM
import numpy as np

mesh = GooseFEM.Mesh.Quad4.Regular(3, 3)

system = model.System(
    mesh.coor(),
    mesh.conn(),
    mesh.dofs(),
    np.array([0, 1]),
    np.arange(6),
    6 + np.arange(3),
)

system.setMassMatrix(np.ones(9))
system.setDampingMatrix(np.ones(9))
system.setElastic(np.ones(6), np.ones(6))
system.setPlastic(np.ones(3), np.ones(3), np.cumsum(np.ones((3, 4)), axis=1))
system.setDt(1)

dV = system.quad().AsTensor(2, system.quad().dV())
