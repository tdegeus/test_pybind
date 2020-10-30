from setuptools import setup, Extension

import re
import os
import pybind11
import pyxtensor

include_dirs = [
    os.path.abspath('./'),
    pyxtensor.find_pyxtensor(),
    pyxtensor.find_pybind11(),
    pyxtensor.find_xtensor(),
    pyxtensor.find_xtl()]

build = pyxtensor.BuildExt

ext_modules = [Extension(
    'mylib',
    ['main.cpp'],
    include_dirs = include_dirs,
    language = 'c++')]

setup(
    name = 'mylib',
    description = '...',
    long_description = '...',
    keywords = '...',
    version = '0.0.1',
    license = 'MIT',
    author = 'Tom de Geus',
    author_email = 'tom@geus.me',
    url = 'https://github.com/tdegeus/test_pybind',
    ext_modules = ext_modules,
    install_requires = ['pybind11>=2.2.0', 'pyxtensor>=0.1.1'],
    cmdclass = {'build_ext': build},
    zip_safe = False)
