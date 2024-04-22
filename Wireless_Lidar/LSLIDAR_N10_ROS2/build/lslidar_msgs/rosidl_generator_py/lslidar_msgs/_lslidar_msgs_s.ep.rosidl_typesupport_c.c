// generated from rosidl_generator_py/resource/_idl_pkg_typesupport_entry_point.c.em
// generated code does not contain a copyright notice
#include <Python.h>

static PyMethodDef lslidar_msgs__methods[] = {
  {NULL, NULL, 0, NULL}  /* sentinel */
};

static struct PyModuleDef lslidar_msgs__module = {
  PyModuleDef_HEAD_INIT,
  "_lslidar_msgs_support",
  "_lslidar_msgs_doc",
  -1,  /* -1 means that the module keeps state in global variables */
  lslidar_msgs__methods,
  NULL,
  NULL,
  NULL,
  NULL,
};

#include <stdbool.h>
#include <stdint.h>
#include "rosidl_runtime_c/visibility_control.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "lslidar_msgs/msg/detail/lslidar_difop__type_support.h"
#include "lslidar_msgs/msg/detail/lslidar_difop__struct.h"
#include "lslidar_msgs/msg/detail/lslidar_difop__functions.h"

static void * lslidar_msgs__msg__lslidar_difop__create_ros_message(void)
{
  return lslidar_msgs__msg__LslidarDifop__create();
}

static void lslidar_msgs__msg__lslidar_difop__destroy_ros_message(void * raw_ros_message)
{
  lslidar_msgs__msg__LslidarDifop * ros_message = (lslidar_msgs__msg__LslidarDifop *)raw_ros_message;
  lslidar_msgs__msg__LslidarDifop__destroy(ros_message);
}

ROSIDL_GENERATOR_C_IMPORT
bool lslidar_msgs__msg__lslidar_difop__convert_from_py(PyObject * _pymsg, void * ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * lslidar_msgs__msg__lslidar_difop__convert_to_py(void * raw_ros_message);


ROSIDL_GENERATOR_C_IMPORT
const rosidl_message_type_support_t *
ROSIDL_GET_MSG_TYPE_SUPPORT(lslidar_msgs, msg, LslidarDifop);

int8_t
_register_msg_type__msg__lslidar_difop(PyObject * pymodule)
{
  int8_t err;

  PyObject * pyobject_create_ros_message = NULL;
  pyobject_create_ros_message = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_difop__create_ros_message,
    NULL, NULL);
  if (!pyobject_create_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "create_ros_message_msg__msg__lslidar_difop",
    pyobject_create_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_create_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_destroy_ros_message = NULL;
  pyobject_destroy_ros_message = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_difop__destroy_ros_message,
    NULL, NULL);
  if (!pyobject_destroy_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "destroy_ros_message_msg__msg__lslidar_difop",
    pyobject_destroy_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_destroy_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_from_py = NULL;
  pyobject_convert_from_py = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_difop__convert_from_py,
    NULL, NULL);
  if (!pyobject_convert_from_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_from_py_msg__msg__lslidar_difop",
    pyobject_convert_from_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_from_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_to_py = NULL;
  pyobject_convert_to_py = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_difop__convert_to_py,
    NULL, NULL);
  if (!pyobject_convert_to_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_to_py_msg__msg__lslidar_difop",
    pyobject_convert_to_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_to_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_type_support = NULL;
  pyobject_type_support = PyCapsule_New(
    (void *)ROSIDL_GET_MSG_TYPE_SUPPORT(lslidar_msgs, msg, LslidarDifop),
    NULL, NULL);
  if (!pyobject_type_support) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "type_support_msg__msg__lslidar_difop",
    pyobject_type_support);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_type_support);
    // previously added objects will be removed when the module is destroyed
    return err;
  }
  return 0;
}

// already included above
// #include <stdbool.h>
// already included above
// #include <stdint.h>
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/action_type_support_struct.h"
#include "lslidar_msgs/msg/detail/lslidar_packet__type_support.h"
#include "lslidar_msgs/msg/detail/lslidar_packet__struct.h"
#include "lslidar_msgs/msg/detail/lslidar_packet__functions.h"

static void * lslidar_msgs__msg__lslidar_packet__create_ros_message(void)
{
  return lslidar_msgs__msg__LslidarPacket__create();
}

static void lslidar_msgs__msg__lslidar_packet__destroy_ros_message(void * raw_ros_message)
{
  lslidar_msgs__msg__LslidarPacket * ros_message = (lslidar_msgs__msg__LslidarPacket *)raw_ros_message;
  lslidar_msgs__msg__LslidarPacket__destroy(ros_message);
}

ROSIDL_GENERATOR_C_IMPORT
bool lslidar_msgs__msg__lslidar_packet__convert_from_py(PyObject * _pymsg, void * ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * lslidar_msgs__msg__lslidar_packet__convert_to_py(void * raw_ros_message);


ROSIDL_GENERATOR_C_IMPORT
const rosidl_message_type_support_t *
ROSIDL_GET_MSG_TYPE_SUPPORT(lslidar_msgs, msg, LslidarPacket);

int8_t
_register_msg_type__msg__lslidar_packet(PyObject * pymodule)
{
  int8_t err;

  PyObject * pyobject_create_ros_message = NULL;
  pyobject_create_ros_message = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_packet__create_ros_message,
    NULL, NULL);
  if (!pyobject_create_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "create_ros_message_msg__msg__lslidar_packet",
    pyobject_create_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_create_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_destroy_ros_message = NULL;
  pyobject_destroy_ros_message = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_packet__destroy_ros_message,
    NULL, NULL);
  if (!pyobject_destroy_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "destroy_ros_message_msg__msg__lslidar_packet",
    pyobject_destroy_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_destroy_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_from_py = NULL;
  pyobject_convert_from_py = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_packet__convert_from_py,
    NULL, NULL);
  if (!pyobject_convert_from_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_from_py_msg__msg__lslidar_packet",
    pyobject_convert_from_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_from_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_to_py = NULL;
  pyobject_convert_to_py = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_packet__convert_to_py,
    NULL, NULL);
  if (!pyobject_convert_to_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_to_py_msg__msg__lslidar_packet",
    pyobject_convert_to_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_to_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_type_support = NULL;
  pyobject_type_support = PyCapsule_New(
    (void *)ROSIDL_GET_MSG_TYPE_SUPPORT(lslidar_msgs, msg, LslidarPacket),
    NULL, NULL);
  if (!pyobject_type_support) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "type_support_msg__msg__lslidar_packet",
    pyobject_type_support);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_type_support);
    // previously added objects will be removed when the module is destroyed
    return err;
  }
  return 0;
}

// already included above
// #include <stdbool.h>
// already included above
// #include <stdint.h>
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/action_type_support_struct.h"
#include "lslidar_msgs/msg/detail/lslidar_point__type_support.h"
#include "lslidar_msgs/msg/detail/lslidar_point__struct.h"
#include "lslidar_msgs/msg/detail/lslidar_point__functions.h"

static void * lslidar_msgs__msg__lslidar_point__create_ros_message(void)
{
  return lslidar_msgs__msg__LslidarPoint__create();
}

static void lslidar_msgs__msg__lslidar_point__destroy_ros_message(void * raw_ros_message)
{
  lslidar_msgs__msg__LslidarPoint * ros_message = (lslidar_msgs__msg__LslidarPoint *)raw_ros_message;
  lslidar_msgs__msg__LslidarPoint__destroy(ros_message);
}

ROSIDL_GENERATOR_C_IMPORT
bool lslidar_msgs__msg__lslidar_point__convert_from_py(PyObject * _pymsg, void * ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * lslidar_msgs__msg__lslidar_point__convert_to_py(void * raw_ros_message);


ROSIDL_GENERATOR_C_IMPORT
const rosidl_message_type_support_t *
ROSIDL_GET_MSG_TYPE_SUPPORT(lslidar_msgs, msg, LslidarPoint);

int8_t
_register_msg_type__msg__lslidar_point(PyObject * pymodule)
{
  int8_t err;

  PyObject * pyobject_create_ros_message = NULL;
  pyobject_create_ros_message = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_point__create_ros_message,
    NULL, NULL);
  if (!pyobject_create_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "create_ros_message_msg__msg__lslidar_point",
    pyobject_create_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_create_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_destroy_ros_message = NULL;
  pyobject_destroy_ros_message = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_point__destroy_ros_message,
    NULL, NULL);
  if (!pyobject_destroy_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "destroy_ros_message_msg__msg__lslidar_point",
    pyobject_destroy_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_destroy_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_from_py = NULL;
  pyobject_convert_from_py = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_point__convert_from_py,
    NULL, NULL);
  if (!pyobject_convert_from_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_from_py_msg__msg__lslidar_point",
    pyobject_convert_from_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_from_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_to_py = NULL;
  pyobject_convert_to_py = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_point__convert_to_py,
    NULL, NULL);
  if (!pyobject_convert_to_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_to_py_msg__msg__lslidar_point",
    pyobject_convert_to_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_to_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_type_support = NULL;
  pyobject_type_support = PyCapsule_New(
    (void *)ROSIDL_GET_MSG_TYPE_SUPPORT(lslidar_msgs, msg, LslidarPoint),
    NULL, NULL);
  if (!pyobject_type_support) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "type_support_msg__msg__lslidar_point",
    pyobject_type_support);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_type_support);
    // previously added objects will be removed when the module is destroyed
    return err;
  }
  return 0;
}

// already included above
// #include <stdbool.h>
// already included above
// #include <stdint.h>
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/action_type_support_struct.h"
#include "lslidar_msgs/msg/detail/lslidar_scan__type_support.h"
#include "lslidar_msgs/msg/detail/lslidar_scan__struct.h"
#include "lslidar_msgs/msg/detail/lslidar_scan__functions.h"

static void * lslidar_msgs__msg__lslidar_scan__create_ros_message(void)
{
  return lslidar_msgs__msg__LslidarScan__create();
}

static void lslidar_msgs__msg__lslidar_scan__destroy_ros_message(void * raw_ros_message)
{
  lslidar_msgs__msg__LslidarScan * ros_message = (lslidar_msgs__msg__LslidarScan *)raw_ros_message;
  lslidar_msgs__msg__LslidarScan__destroy(ros_message);
}

ROSIDL_GENERATOR_C_IMPORT
bool lslidar_msgs__msg__lslidar_scan__convert_from_py(PyObject * _pymsg, void * ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * lslidar_msgs__msg__lslidar_scan__convert_to_py(void * raw_ros_message);


ROSIDL_GENERATOR_C_IMPORT
const rosidl_message_type_support_t *
ROSIDL_GET_MSG_TYPE_SUPPORT(lslidar_msgs, msg, LslidarScan);

int8_t
_register_msg_type__msg__lslidar_scan(PyObject * pymodule)
{
  int8_t err;

  PyObject * pyobject_create_ros_message = NULL;
  pyobject_create_ros_message = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_scan__create_ros_message,
    NULL, NULL);
  if (!pyobject_create_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "create_ros_message_msg__msg__lslidar_scan",
    pyobject_create_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_create_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_destroy_ros_message = NULL;
  pyobject_destroy_ros_message = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_scan__destroy_ros_message,
    NULL, NULL);
  if (!pyobject_destroy_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "destroy_ros_message_msg__msg__lslidar_scan",
    pyobject_destroy_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_destroy_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_from_py = NULL;
  pyobject_convert_from_py = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_scan__convert_from_py,
    NULL, NULL);
  if (!pyobject_convert_from_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_from_py_msg__msg__lslidar_scan",
    pyobject_convert_from_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_from_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_to_py = NULL;
  pyobject_convert_to_py = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_scan__convert_to_py,
    NULL, NULL);
  if (!pyobject_convert_to_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_to_py_msg__msg__lslidar_scan",
    pyobject_convert_to_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_to_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_type_support = NULL;
  pyobject_type_support = PyCapsule_New(
    (void *)ROSIDL_GET_MSG_TYPE_SUPPORT(lslidar_msgs, msg, LslidarScan),
    NULL, NULL);
  if (!pyobject_type_support) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "type_support_msg__msg__lslidar_scan",
    pyobject_type_support);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_type_support);
    // previously added objects will be removed when the module is destroyed
    return err;
  }
  return 0;
}

// already included above
// #include <stdbool.h>
// already included above
// #include <stdint.h>
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_runtime_c/action_type_support_struct.h"
#include "lslidar_msgs/msg/detail/lslidar_sweep__type_support.h"
#include "lslidar_msgs/msg/detail/lslidar_sweep__struct.h"
#include "lslidar_msgs/msg/detail/lslidar_sweep__functions.h"

static void * lslidar_msgs__msg__lslidar_sweep__create_ros_message(void)
{
  return lslidar_msgs__msg__LslidarSweep__create();
}

static void lslidar_msgs__msg__lslidar_sweep__destroy_ros_message(void * raw_ros_message)
{
  lslidar_msgs__msg__LslidarSweep * ros_message = (lslidar_msgs__msg__LslidarSweep *)raw_ros_message;
  lslidar_msgs__msg__LslidarSweep__destroy(ros_message);
}

ROSIDL_GENERATOR_C_IMPORT
bool lslidar_msgs__msg__lslidar_sweep__convert_from_py(PyObject * _pymsg, void * ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * lslidar_msgs__msg__lslidar_sweep__convert_to_py(void * raw_ros_message);


ROSIDL_GENERATOR_C_IMPORT
const rosidl_message_type_support_t *
ROSIDL_GET_MSG_TYPE_SUPPORT(lslidar_msgs, msg, LslidarSweep);

int8_t
_register_msg_type__msg__lslidar_sweep(PyObject * pymodule)
{
  int8_t err;

  PyObject * pyobject_create_ros_message = NULL;
  pyobject_create_ros_message = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_sweep__create_ros_message,
    NULL, NULL);
  if (!pyobject_create_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "create_ros_message_msg__msg__lslidar_sweep",
    pyobject_create_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_create_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_destroy_ros_message = NULL;
  pyobject_destroy_ros_message = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_sweep__destroy_ros_message,
    NULL, NULL);
  if (!pyobject_destroy_ros_message) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "destroy_ros_message_msg__msg__lslidar_sweep",
    pyobject_destroy_ros_message);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_destroy_ros_message);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_from_py = NULL;
  pyobject_convert_from_py = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_sweep__convert_from_py,
    NULL, NULL);
  if (!pyobject_convert_from_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_from_py_msg__msg__lslidar_sweep",
    pyobject_convert_from_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_from_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_convert_to_py = NULL;
  pyobject_convert_to_py = PyCapsule_New(
    (void *)&lslidar_msgs__msg__lslidar_sweep__convert_to_py,
    NULL, NULL);
  if (!pyobject_convert_to_py) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "convert_to_py_msg__msg__lslidar_sweep",
    pyobject_convert_to_py);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_convert_to_py);
    // previously added objects will be removed when the module is destroyed
    return err;
  }

  PyObject * pyobject_type_support = NULL;
  pyobject_type_support = PyCapsule_New(
    (void *)ROSIDL_GET_MSG_TYPE_SUPPORT(lslidar_msgs, msg, LslidarSweep),
    NULL, NULL);
  if (!pyobject_type_support) {
    // previously added objects will be removed when the module is destroyed
    return -1;
  }
  err = PyModule_AddObject(
    pymodule,
    "type_support_msg__msg__lslidar_sweep",
    pyobject_type_support);
  if (err) {
    // the created capsule needs to be decremented
    Py_XDECREF(pyobject_type_support);
    // previously added objects will be removed when the module is destroyed
    return err;
  }
  return 0;
}

PyMODINIT_FUNC
PyInit_lslidar_msgs_s__rosidl_typesupport_c(void)
{
  PyObject * pymodule = NULL;
  pymodule = PyModule_Create(&lslidar_msgs__module);
  if (!pymodule) {
    return NULL;
  }
  int8_t err;

  err = _register_msg_type__msg__lslidar_difop(pymodule);
  if (err) {
    Py_XDECREF(pymodule);
    return NULL;
  }

  err = _register_msg_type__msg__lslidar_packet(pymodule);
  if (err) {
    Py_XDECREF(pymodule);
    return NULL;
  }

  err = _register_msg_type__msg__lslidar_point(pymodule);
  if (err) {
    Py_XDECREF(pymodule);
    return NULL;
  }

  err = _register_msg_type__msg__lslidar_scan(pymodule);
  if (err) {
    Py_XDECREF(pymodule);
    return NULL;
  }

  err = _register_msg_type__msg__lslidar_sweep(pymodule);
  if (err) {
    Py_XDECREF(pymodule);
    return NULL;
  }

  return pymodule;
}
