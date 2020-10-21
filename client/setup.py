from setuptools import Extension, setup
from setuptools.command.build_ext import build_ext as build_ext_orig

# Decides whether to build with Cython from .pyx file or the autogenerated c++ source
try: 
    from Cython.Distutils import build_ext
except ImportError:
    use_cython = False
else:
    use_cython = True

if use_cython:
    from Cython.Build import cythonize
    setup(
        name = "client_methods",
        ext_modules=cythonize(Extension(
                            name="client_methods",
                            sources=["client_methods.pyx", "../common/encryption/encrypt.cpp", "../common/encryption/serialization.cpp"],
                            language="c++",
                            libraries=["mbedtls", "mbedcrypto"],
                            include_dirs=['/usr/include/mbedtls', '/usr/include/mbedcrypto']
            ),
        )
    )
else:
    setup(
        name = "client_methods",
        ext_modules=([Extension(
                            name="client_methods",
                            sources=["client_methods.cpp", "../common/encryption/encrypt.cpp", "../common/encryption/serialization.cpp"],
                            language="c++",
                            libraries=["mbedtls", "mbedcrypto"],
                            include_dirs=['/usr/include/mbedtls', '/usr/include/mbedcrypto']]
            ),
        )
    )

