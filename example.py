import FrictionQPotFEM.UniformSingleLayer2d as model
import GMatElastoPlasticQPot.Cartesian2d as GMat
import GooseFEM
import numpy as np

coor = np.array(
[[0., 0.],
 [1., 0.],
 [2., 0.],
 [3., 0.],
 [0., 1.],
 [1., 1.],
 [2., 1.],
 [3., 1.],
 [0., 2.],
 [1., 2.],
 [2., 2.],
 [3., 2.],
 [0., 3.],
 [1., 3.],
 [2., 3.],
 [3., 3.]])

conn = np.array(
[[ 0,  1,  5,  4],
 [ 1,  2,  6,  5],
 [ 2,  3,  7,  6],
 [ 4,  5,  9,  8],
 [ 5,  6, 10,  9],
 [ 6,  7, 11, 10],
 [ 8,  9, 13, 12],
 [ 9, 10, 14, 13],
 [10, 11, 15, 14]], dtype=np.uint64)

dofs = np.array(
[[ 0,  1],
 [ 2,  3],
 [ 4,  5],
 [ 6,  7],
 [ 8,  9],
 [10, 11],
 [12, 13],
 [14, 15],
 [16, 17],
 [18, 19],
 [20, 21],
 [22, 23],
 [24, 25],
 [26, 27],
 [28, 29],
 [30, 31]], dtype=np.uint64)

system = model.System(
    coor,
    conn,
    dofs,
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
print(dV)
