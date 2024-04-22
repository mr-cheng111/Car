// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from lslidar_msgs:msg/LslidarDifop.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "lslidar_msgs/msg/detail/lslidar_difop__struct.h"
#include "lslidar_msgs/msg/detail/lslidar_difop__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool lslidar_msgs__msg__lslidar_difop__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("lslidar_msgs.msg._lslidar_difop.LslidarDifop", full_classname_dest, 44) == 0);
  }
  lslidar_msgs__msg__LslidarDifop * ros_message = _ros_message;
  {  // temperature
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->temperature = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }
  {  // rpm
    PyObject * field = PyObject_GetAttrString(_pymsg, "rpm");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rpm = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * lslidar_msgs__msg__lslidar_difop__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LslidarDifop */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("lslidar_msgs.msg._lslidar_difop");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LslidarDifop");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  lslidar_msgs__msg__LslidarDifop * ros_message = (lslidar_msgs__msg__LslidarDifop *)raw_ros_message;
  {  // temperature
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->temperature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rpm
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->rpm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rpm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
