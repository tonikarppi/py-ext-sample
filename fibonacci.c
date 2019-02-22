#include <Python.h>
#include <stdint.h>

int64_t fibonacci(int32_t n)
{
  int64_t a = 0;
  int64_t b = 1;

  for (int32_t i = 1; i < n; ++i)
  {
    int64_t s = a + b;
    a = b;
    b = s;
  }

  return b;
}

static PyObject *fib_object(PyObject *self, PyObject *args)
{
  int n;

  if (!PyArg_ParseTuple(args, "i", &n))
  {
    // Parsing failed.
    return NULL;
  }

  return Py_BuildValue("i", fibonacci(n));
}

static PyObject *version_object(PyObject *self)
{
  return Py_BuildValue("s", "1.0.0");
}

static PyMethodDef methods[] = {
    {"fib", fib_object, METH_VARARGS, "Calculates the fibonacci numbers."},
    {"version", (PyCFunction)version_object, METH_NOARGS, "Returns the program version."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef fibonacci_module = {
    PyModuleDef_HEAD_INIT,
    "fibonacci",
    "Fibonacci module",
    -1,
    methods};

PyMODINIT_FUNC PyInit_fibonacci(void)
{
  return PyModule_Create(&fibonacci_module);
}
