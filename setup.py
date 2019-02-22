from distutils.core import setup, Extension

module = Extension("fibonacci", sources=["fibonacci.c"])

setup(
    name="Fibonacci",
    version="0.0.1",
    description="Cool fibonacci program.",
    ext_modules=[module],
)

