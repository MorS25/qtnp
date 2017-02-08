# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from qtnp/Placemarks.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import qtnp.msg

class Placemarks(genpy.Message):
  _md5sum = "d412150a28aefbf6a830287329e8685d"
  _type = "qtnp/Placemarks"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """qtnp/Coordinates[] placemarks 

================================================================================
MSG: qtnp/Coordinates
string placemark_type
float64 seed_longitude
float64 seed_latitude
float64[] longitude
float64[] latitude
"""
  __slots__ = ['placemarks']
  _slot_types = ['qtnp/Coordinates[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       placemarks

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Placemarks, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.placemarks is None:
        self.placemarks = []
    else:
      self.placemarks = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      length = len(self.placemarks)
      buff.write(_struct_I.pack(length))
      for val1 in self.placemarks:
        _x = val1.placemark_type
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_2d().pack(_x.seed_longitude, _x.seed_latitude))
        length = len(val1.longitude)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(struct.pack(pattern, *val1.longitude))
        length = len(val1.latitude)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(struct.pack(pattern, *val1.latitude))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.placemarks is None:
        self.placemarks = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.placemarks = []
      for i in range(0, length):
        val1 = qtnp.msg.Coordinates()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.placemark_type = str[start:end].decode('utf-8')
        else:
          val1.placemark_type = str[start:end]
        _x = val1
        start = end
        end += 16
        (_x.seed_longitude, _x.seed_latitude,) = _get_struct_2d().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        val1.longitude = struct.unpack(pattern, str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        val1.latitude = struct.unpack(pattern, str[start:end])
        self.placemarks.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      length = len(self.placemarks)
      buff.write(_struct_I.pack(length))
      for val1 in self.placemarks:
        _x = val1.placemark_type
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_2d().pack(_x.seed_longitude, _x.seed_latitude))
        length = len(val1.longitude)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(val1.longitude.tostring())
        length = len(val1.latitude)
        buff.write(_struct_I.pack(length))
        pattern = '<%sd'%length
        buff.write(val1.latitude.tostring())
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.placemarks is None:
        self.placemarks = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.placemarks = []
      for i in range(0, length):
        val1 = qtnp.msg.Coordinates()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.placemark_type = str[start:end].decode('utf-8')
        else:
          val1.placemark_type = str[start:end]
        _x = val1
        start = end
        end += 16
        (_x.seed_longitude, _x.seed_latitude,) = _get_struct_2d().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        val1.longitude = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        pattern = '<%sd'%length
        start = end
        end += struct.calcsize(pattern)
        val1.latitude = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
        self.placemarks.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2d = None
def _get_struct_2d():
    global _struct_2d
    if _struct_2d is None:
        _struct_2d = struct.Struct("<2d")
    return _struct_2d
