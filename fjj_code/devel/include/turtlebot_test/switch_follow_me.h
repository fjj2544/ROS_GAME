// Generated by gencpp from file turtlebot_test/switch_follow_me.msg
// DO NOT EDIT!


#ifndef TURTLEBOT_TEST_MESSAGE_SWITCH_FOLLOW_ME_H
#define TURTLEBOT_TEST_MESSAGE_SWITCH_FOLLOW_ME_H

#include <ros/service_traits.h>


#include <turtlebot_test/switch_follow_meRequest.h>
#include <turtlebot_test/switch_follow_meResponse.h>


namespace turtlebot_test
{

struct switch_follow_me
{

typedef switch_follow_meRequest Request;
typedef switch_follow_meResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct switch_follow_me
} // namespace turtlebot_test


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::turtlebot_test::switch_follow_me > {
  static const char* value()
  {
    return "fd72814fc41c6bccdf8759d8dea09f77";
  }

  static const char* value(const ::turtlebot_test::switch_follow_me&) { return value(); }
};

template<>
struct DataType< ::turtlebot_test::switch_follow_me > {
  static const char* value()
  {
    return "turtlebot_test/switch_follow_me";
  }

  static const char* value(const ::turtlebot_test::switch_follow_me&) { return value(); }
};


// service_traits::MD5Sum< ::turtlebot_test::switch_follow_meRequest> should match 
// service_traits::MD5Sum< ::turtlebot_test::switch_follow_me > 
template<>
struct MD5Sum< ::turtlebot_test::switch_follow_meRequest>
{
  static const char* value()
  {
    return MD5Sum< ::turtlebot_test::switch_follow_me >::value();
  }
  static const char* value(const ::turtlebot_test::switch_follow_meRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::turtlebot_test::switch_follow_meRequest> should match 
// service_traits::DataType< ::turtlebot_test::switch_follow_me > 
template<>
struct DataType< ::turtlebot_test::switch_follow_meRequest>
{
  static const char* value()
  {
    return DataType< ::turtlebot_test::switch_follow_me >::value();
  }
  static const char* value(const ::turtlebot_test::switch_follow_meRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::turtlebot_test::switch_follow_meResponse> should match 
// service_traits::MD5Sum< ::turtlebot_test::switch_follow_me > 
template<>
struct MD5Sum< ::turtlebot_test::switch_follow_meResponse>
{
  static const char* value()
  {
    return MD5Sum< ::turtlebot_test::switch_follow_me >::value();
  }
  static const char* value(const ::turtlebot_test::switch_follow_meResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::turtlebot_test::switch_follow_meResponse> should match 
// service_traits::DataType< ::turtlebot_test::switch_follow_me > 
template<>
struct DataType< ::turtlebot_test::switch_follow_meResponse>
{
  static const char* value()
  {
    return DataType< ::turtlebot_test::switch_follow_me >::value();
  }
  static const char* value(const ::turtlebot_test::switch_follow_meResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TURTLEBOT_TEST_MESSAGE_SWITCH_FOLLOW_ME_H
