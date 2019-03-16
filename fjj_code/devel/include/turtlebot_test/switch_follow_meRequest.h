// Generated by gencpp from file turtlebot_test/switch_follow_meRequest.msg
// DO NOT EDIT!


#ifndef TURTLEBOT_TEST_MESSAGE_SWITCH_FOLLOW_MEREQUEST_H
#define TURTLEBOT_TEST_MESSAGE_SWITCH_FOLLOW_MEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace turtlebot_test
{
template <class ContainerAllocator>
struct switch_follow_meRequest_
{
  typedef switch_follow_meRequest_<ContainerAllocator> Type;

  switch_follow_meRequest_()
    : req()  {
    }
  switch_follow_meRequest_(const ContainerAllocator& _alloc)
    : req(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _req_type;
  _req_type req;





  typedef boost::shared_ptr< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> const> ConstPtr;

}; // struct switch_follow_meRequest_

typedef ::turtlebot_test::switch_follow_meRequest_<std::allocator<void> > switch_follow_meRequest;

typedef boost::shared_ptr< ::turtlebot_test::switch_follow_meRequest > switch_follow_meRequestPtr;
typedef boost::shared_ptr< ::turtlebot_test::switch_follow_meRequest const> switch_follow_meRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace turtlebot_test

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b8dc53fbc3707f169aa5dbf7b19d2567";
  }

  static const char* value(const ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb8dc53fbc3707f16ULL;
  static const uint64_t static_value2 = 0x9aa5dbf7b19d2567ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlebot_test/switch_follow_meRequest";
  }

  static const char* value(const ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string req\n\
";
  }

  static const char* value(const ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.req);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct switch_follow_meRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlebot_test::switch_follow_meRequest_<ContainerAllocator>& v)
  {
    s << indent << "req: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.req);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLEBOT_TEST_MESSAGE_SWITCH_FOLLOW_MEREQUEST_H
