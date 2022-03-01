import numpy as np
import mymodule

A = np.random.random((10, 5))
i = mymodule.myfunc(A)
j = np.unravel_index(np.argmin(A), A.shape)
assert i == list(j)
