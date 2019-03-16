// Generated by gencpp from file test1/mysrvResponse.msg
// DO NOT EDIT!


#ifndef TEST1_MESSAGE_MYSRVRESPONSE_H
#define TEST1_MESSAGE_MYSRVRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace test1
{
template <class ContainerAllocator>
struct mysrvResponse_
{
  typedef mysrvResponse_<ContainerAllocator> Type;

  mysrvResponse_()
    : sum(0)  {
    }
  mysrvResponse_(const ContainerAllocator& _alloc)
    : sum(0)  {
  (void)_alloc;
    }



   typedef int32_t _sum_type;
  _sum_type sum;





  typedef boost::shared_ptr< ::test1::mysrvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test1::mysrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct mysrvResponse_

typedef ::test1::mysrvResponse_<std::allocator<void> > mysrvResponse;

typedef boost::shared_ptr< ::test1::mysrvResponse > mysrvResponsePtr;
typedef boost::shared_ptr< ::test1::mysrvResponse const> mysrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test1::mysrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test1::mysrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace test1

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'test1': ['/home/fjj/documents/fjj_ros_code/fjj_code/src/test1/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::test1::mysrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test1::mysrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test1::mysrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test1::mysrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test1::mysrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test1::mysrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test1::mysrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0ba699c25c9418c0366f3595c0c8e8ec";
  }

  static const char* value(const ::test1::mysrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0ba699c25c9418c0ULL;
  static const uint64_t static_value2 = 0x366f3595c0c8e8ecULL;
};

template<class ContainerAllocator>
struct DataType< ::test1::mysrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test1/mysrvResponse";
  }

  static const char* value(const ::test1::mysrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test1::mysrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 sum\n\
\n\
";
  }

  static const char* value(const ::test1::mysrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test1::mysrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.sum);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct mysrvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test1::mysrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test1::mysrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "sum: ";
    Printer<int32_t>::stream(s, indent + "  ", v.sum);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST1_MESSAGE_MYSRVRESPONSE_H