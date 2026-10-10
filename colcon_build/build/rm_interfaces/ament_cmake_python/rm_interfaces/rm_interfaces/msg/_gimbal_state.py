# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_interfaces:msg/GimbalState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GimbalState(type):
    """Metaclass of message 'GimbalState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'MODE_IDLE': 0,
        'MODE_AUTO_AIM': 1,
        'MODE_SMALL_BUFF': 2,
        'MODE_BIG_BUFF': 3,
        'MODE_OUTPOST': 4,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rm_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rm_interfaces.msg.GimbalState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gimbal_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gimbal_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gimbal_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gimbal_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gimbal_state

            from geometry_msgs.msg import Quaternion
            if Quaternion.__class__._TYPE_SUPPORT is None:
                Quaternion.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'MODE_IDLE': cls.__constants['MODE_IDLE'],
            'MODE_AUTO_AIM': cls.__constants['MODE_AUTO_AIM'],
            'MODE_SMALL_BUFF': cls.__constants['MODE_SMALL_BUFF'],
            'MODE_BIG_BUFF': cls.__constants['MODE_BIG_BUFF'],
            'MODE_OUTPOST': cls.__constants['MODE_OUTPOST'],
        }

    @property
    def MODE_IDLE(self):
        """Message constant 'MODE_IDLE'."""
        return Metaclass_GimbalState.__constants['MODE_IDLE']

    @property
    def MODE_AUTO_AIM(self):
        """Message constant 'MODE_AUTO_AIM'."""
        return Metaclass_GimbalState.__constants['MODE_AUTO_AIM']

    @property
    def MODE_SMALL_BUFF(self):
        """Message constant 'MODE_SMALL_BUFF'."""
        return Metaclass_GimbalState.__constants['MODE_SMALL_BUFF']

    @property
    def MODE_BIG_BUFF(self):
        """Message constant 'MODE_BIG_BUFF'."""
        return Metaclass_GimbalState.__constants['MODE_BIG_BUFF']

    @property
    def MODE_OUTPOST(self):
        """Message constant 'MODE_OUTPOST'."""
        return Metaclass_GimbalState.__constants['MODE_OUTPOST']


class GimbalState(metaclass=Metaclass_GimbalState):
    """
    Message class 'GimbalState'.

    Constants:
      MODE_IDLE
      MODE_AUTO_AIM
      MODE_SMALL_BUFF
      MODE_BIG_BUFF
      MODE_OUTPOST
    """

    __slots__ = [
        '_header',
        '_quaternion',
        '_bullet_speed',
        '_mode',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'quaternion': 'geometry_msgs/Quaternion',
        'bullet_speed': 'float',
        'mode': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Quaternion'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from geometry_msgs.msg import Quaternion
        self.quaternion = kwargs.get('quaternion', Quaternion())
        self.bullet_speed = kwargs.get('bullet_speed', float())
        self.mode = kwargs.get('mode', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.quaternion != other.quaternion:
            return False
        if self.bullet_speed != other.bullet_speed:
            return False
        if self.mode != other.mode:
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
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def quaternion(self):
        """Message field 'quaternion'."""
        return self._quaternion

    @quaternion.setter
    def quaternion(self, value):
        if __debug__:
            from geometry_msgs.msg import Quaternion
            assert \
                isinstance(value, Quaternion), \
                "The 'quaternion' field must be a sub message of type 'Quaternion'"
        self._quaternion = value

    @builtins.property
    def bullet_speed(self):
        """Message field 'bullet_speed'."""
        return self._bullet_speed

    @bullet_speed.setter
    def bullet_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bullet_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bullet_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bullet_speed = value

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'mode' field must be an unsigned integer in [0, 255]"
        self._mode = value
