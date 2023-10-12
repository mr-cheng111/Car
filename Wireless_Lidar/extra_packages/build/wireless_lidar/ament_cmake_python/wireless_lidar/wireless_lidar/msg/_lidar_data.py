# generated from rosidl_generator_py/resource/_idl.py.em
# with input from wireless_lidar:msg/LidarData.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LidarData(type):
    """Metaclass of message 'LidarData'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('wireless_lidar')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'wireless_lidar.msg.LidarData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__lidar_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__lidar_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__lidar_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__lidar_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__lidar_data

            from wireless_lidar.msg import PointData
            if PointData.__class__._TYPE_SUPPORT is None:
                PointData.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LidarData(metaclass=Metaclass_LidarData):
    """Message class 'LidarData'."""

    __slots__ = [
        '_header',
        '_pkg_length',
        '_rate',
        '_start_angle',
        '_data',
        '_stop_angle',
        '_sum_data',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'uint16',
        'pkg_length': 'uint8',
        'rate': 'uint16',
        'start_angle': 'uint16',
        'data': 'wireless_lidar/PointData[16]',
        'stop_angle': 'uint16',
        'sum_data': 'uint8',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.NamespacedType(['wireless_lidar', 'msg'], 'PointData'), 16),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.header = kwargs.get('header', int())
        self.pkg_length = kwargs.get('pkg_length', int())
        self.rate = kwargs.get('rate', int())
        self.start_angle = kwargs.get('start_angle', int())
        from wireless_lidar.msg import PointData
        self.data = kwargs.get(
            'data',
            [PointData() for x in range(16)]
        )
        self.stop_angle = kwargs.get('stop_angle', int())
        self.sum_data = kwargs.get('sum_data', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.pkg_length != other.pkg_length:
            return False
        if self.rate != other.rate:
            return False
        if self.start_angle != other.start_angle:
            return False
        if self.data != other.data:
            return False
        if self.stop_angle != other.stop_angle:
            return False
        if self.sum_data != other.sum_data:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'header' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'header' field must be an unsigned integer in [0, 65535]"
        self._header = value

    @builtins.property
    def pkg_length(self):
        """Message field 'pkg_length'."""
        return self._pkg_length

    @pkg_length.setter
    def pkg_length(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'pkg_length' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'pkg_length' field must be an unsigned integer in [0, 255]"
        self._pkg_length = value

    @builtins.property
    def rate(self):
        """Message field 'rate'."""
        return self._rate

    @rate.setter
    def rate(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'rate' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'rate' field must be an unsigned integer in [0, 65535]"
        self._rate = value

    @builtins.property
    def start_angle(self):
        """Message field 'start_angle'."""
        return self._start_angle

    @start_angle.setter
    def start_angle(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'start_angle' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'start_angle' field must be an unsigned integer in [0, 65535]"
        self._start_angle = value

    @builtins.property
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if self._check_fields:
            from wireless_lidar.msg import PointData
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 16 and
                 all(isinstance(v, PointData) for v in value) and
                 True), \
                "The 'data' field must be a set or sequence with length 16 and each value of type 'PointData'"
        self._data = value

    @builtins.property
    def stop_angle(self):
        """Message field 'stop_angle'."""
        return self._stop_angle

    @stop_angle.setter
    def stop_angle(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'stop_angle' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'stop_angle' field must be an unsigned integer in [0, 65535]"
        self._stop_angle = value

    @builtins.property
    def sum_data(self):
        """Message field 'sum_data'."""
        return self._sum_data

    @sum_data.setter
    def sum_data(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'sum_data' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sum_data' field must be an unsigned integer in [0, 255]"
        self._sum_data = value
