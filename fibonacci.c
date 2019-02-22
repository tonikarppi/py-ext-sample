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
