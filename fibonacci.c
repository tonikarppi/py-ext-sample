#include <Python.h>

int fibonacci(int n)
{
  int a = 0;
  int b = 1;

  for (int i = 0; i < n - 1; ++i)
  {
    int s = a + b;
    a = b;
    b = s;
  }

  return b;
}

static PyObject *py_fibonacci(PyObject *self, PyObject *args)
{
  int n;

  if (!PyArg_ParseTuple(args, "i", &n))
  {
    // Parsing failed.
    return NULL;
  }

  return Py_BuildValue("i", fibonacci(n));
}

static PyObject *py_version(PyObject *self)
{
  return Py_BuildValue("s", "1.0.0");
}

static PyMethodDef py_methods[] = {
    {"fib", py_fibonacci, METH_VARARGS, "Calculates the fibonacci numbers."},
    {"version", (PyCFunction)py_version, METH_NOARGS, "Returns the program version."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef fib_module = {
    PyModuleDef_HEAD_INIT,
    "fib_module",
    "Fibonacci module",
    -1,
    py_methods};

PyMODINIT_FUNC PyInit_fib_module(void)
{
  return PyModule_Create(&fib_module);
}
