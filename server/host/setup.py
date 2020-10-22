from setuptools import Extension, setup
from setuptools.command.build_ext import build_ext as build_ext_orig

from Cython.Build import cythonize

setup(
    ext_modules=cythonize(Extension(
                          name="server_methods",
                          sources=["server_methods.pyx"],
                          language="c++",
                          libraries=[""],
                          library_dirs=['.'],
                          include_dirs=['.']
        ),
    )
)

