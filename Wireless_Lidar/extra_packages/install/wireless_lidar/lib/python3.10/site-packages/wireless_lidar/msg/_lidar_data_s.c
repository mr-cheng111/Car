// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from wireless_lidar:msg/LidarData.idl
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
#include "wireless_lidar/msg/detail/lidar_data__struct.h"
#include "wireless_lidar/msg/detail/lidar_data__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "wireless_lidar/msg/detail/point_data__functions.h"
// end nested array functions include
bool wireless_lidar__msg__point_data__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * wireless_lidar__msg__point_data__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool wireless_lidar__msg__lidar_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("wireless_lidar.msg._lidar_data.LidarData", full_classname_dest, 40) == 0);
  }
  wireless_lidar__msg__LidarData * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->header = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // pkg_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "pkg_length");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pkg_length = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // rate
    PyObject * field = PyObject_GetAttrString(_pymsg, "rate");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->rate = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // start_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "start_angle");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->start_angle = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // data
    PyObject * field = PyObject_GetAttrString(_pymsg, "data");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'data'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = 16;
    wireless_lidar__msg__PointData * dest = ros_message->data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!wireless_lidar__msg__point_data__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // stop_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "stop_angle");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->stop_angle = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sum_data
    PyObject * field = PyObject_GetAttrString(_pymsg, "sum_data");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sum_data = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * wireless_lidar__msg__lidar_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LidarData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("wireless_lidar.msg._lidar_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LidarData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  wireless_lidar__msg__LidarData * ros_message = (wireless_lidar__msg__LidarData *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->header);
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pkg_length
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pkg_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pkg_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rate
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->rate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // start_angle
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->start_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "start_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // data
    PyObject * field = NULL;
    size_t size = 16;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    wireless_lidar__msg__PointData * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->data[i]);
      PyObject * pyitem = wireless_lidar__msg__point_data__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "data", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // stop_angle
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->stop_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "stop_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sum_data
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sum_data);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sum_data", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
