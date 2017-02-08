// Generated by gencpp from file qtnp/Coordinates.msg
// DO NOT EDIT!


#ifndef QTNP_MESSAGE_COORDINATES_H
#define QTNP_MESSAGE_COORDINATES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace qtnp
{
template <class ContainerAllocator>
struct Coordinates_
{
  typedef Coordinates_<ContainerAllocator> Type;

  Coordinates_()
    : placemark_type()
    , seed_longitude(0.0)
    , seed_latitude(0.0)
    , longitude()
    , latitude()  {
    }
  Coordinates_(const ContainerAllocator& _alloc)
    : placemark_type(_alloc)
    , seed_longitude(0.0)
    , seed_latitude(0.0)
    , longitude(_alloc)
    , latitude(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _placemark_type_type;
  _placemark_type_type placemark_type;

   typedef double _seed_longitude_type;
  _seed_longitude_type seed_longitude;

   typedef double _seed_latitude_type;
  _seed_latitude_type seed_latitude;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _longitude_type;
  _longitude_type longitude;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _latitude_type;
  _latitude_type latitude;




  typedef boost::shared_ptr< ::qtnp::Coordinates_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::qtnp::Coordinates_<ContainerAllocator> const> ConstPtr;

}; // struct Coordinates_

typedef ::qtnp::Coordinates_<std::allocator<void> > Coordinates;

typedef boost::shared_ptr< ::qtnp::Coordinates > CoordinatesPtr;
typedef boost::shared_ptr< ::qtnp::Coordinates const> CoordinatesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::qtnp::Coordinates_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::qtnp::Coordinates_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace qtnp

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'qtnp': ['/home/fotis/Dev/Workspaces/ROS/qTnP/src/qtnp/msg'], 'visualization_msgs': ['/opt/ros/kinetic/share/visualization_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::qtnp::Coordinates_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::qtnp::Coordinates_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::qtnp::Coordinates_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::qtnp::Coordinates_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qtnp::Coordinates_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::qtnp::Coordinates_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::qtnp::Coordinates_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0c53d7b4e0233648a057076b6c290607";
  }

  static const char* value(const ::qtnp::Coordinates_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0c53d7b4e0233648ULL;
  static const uint64_t static_value2 = 0xa057076b6c290607ULL;
};

template<class ContainerAllocator>
struct DataType< ::qtnp::Coordinates_<ContainerAllocator> >
{
  static const char* value()
  {
    return "qtnp/Coordinates";
  }

  static const char* value(const ::qtnp::Coordinates_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::qtnp::Coordinates_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string placemark_type\n\
float64 seed_longitude\n\
float64 seed_latitude\n\
float64[] longitude\n\
float64[] latitude\n\
";
  }

  static const char* value(const ::qtnp::Coordinates_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::qtnp::Coordinates_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.placemark_type);
      stream.next(m.seed_longitude);
      stream.next(m.seed_latitude);
      stream.next(m.longitude);
      stream.next(m.latitude);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Coordinates_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::qtnp::Coordinates_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::qtnp::Coordinates_<ContainerAllocator>& v)
  {
    s << indent << "placemark_type: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.placemark_type);
    s << indent << "seed_longitude: ";
    Printer<double>::stream(s, indent + "  ", v.seed_longitude);
    s << indent << "seed_latitude: ";
    Printer<double>::stream(s, indent + "  ", v.seed_latitude);
    s << indent << "longitude[]" << std::endl;
    for (size_t i = 0; i < v.longitude.size(); ++i)
    {
      s << indent << "  longitude[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.longitude[i]);
    }
    s << indent << "latitude[]" << std::endl;
    for (size_t i = 0; i < v.latitude.size(); ++i)
    {
      s << indent << "  latitude[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.latitude[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // QTNP_MESSAGE_COORDINATES_H
