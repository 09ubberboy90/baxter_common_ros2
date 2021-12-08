// Generated by gencpp from file baxter_bridge/BaxterPublishers.msg
// DO NOT EDIT!


#ifndef BAXTER_BRIDGE_MESSAGE_BAXTERPUBLISHERS_H
#define BAXTER_BRIDGE_MESSAGE_BAXTERPUBLISHERS_H

#include <ros/service_traits.h>


#include <baxter_bridge/BaxterPublishersRequest.h>
#include <baxter_bridge/BaxterPublishersResponse.h>


namespace baxter_bridge
{

struct BaxterPublishers
{

typedef BaxterPublishersRequest Request;
typedef BaxterPublishersResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct BaxterPublishers
} // namespace baxter_bridge


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::baxter_bridge::BaxterPublishers > {
  static const char* value()
  {
    return "3622d4b9e580cafc5919978ee06bdc53";
  }

  static const char* value(const ::baxter_bridge::BaxterPublishers&) { return value(); }
};

template<>
struct DataType< ::baxter_bridge::BaxterPublishers > {
  static const char* value()
  {
    return "baxter_bridge/BaxterPublishers";
  }

  static const char* value(const ::baxter_bridge::BaxterPublishers&) { return value(); }
};


// service_traits::MD5Sum< ::baxter_bridge::BaxterPublishersRequest> should match
// service_traits::MD5Sum< ::baxter_bridge::BaxterPublishers >
template<>
struct MD5Sum< ::baxter_bridge::BaxterPublishersRequest>
{
  static const char* value()
  {
    return MD5Sum< ::baxter_bridge::BaxterPublishers >::value();
  }
  static const char* value(const ::baxter_bridge::BaxterPublishersRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::baxter_bridge::BaxterPublishersRequest> should match
// service_traits::DataType< ::baxter_bridge::BaxterPublishers >
template<>
struct DataType< ::baxter_bridge::BaxterPublishersRequest>
{
  static const char* value()
  {
    return DataType< ::baxter_bridge::BaxterPublishers >::value();
  }
  static const char* value(const ::baxter_bridge::BaxterPublishersRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::baxter_bridge::BaxterPublishersResponse> should match
// service_traits::MD5Sum< ::baxter_bridge::BaxterPublishers >
template<>
struct MD5Sum< ::baxter_bridge::BaxterPublishersResponse>
{
  static const char* value()
  {
    return MD5Sum< ::baxter_bridge::BaxterPublishers >::value();
  }
  static const char* value(const ::baxter_bridge::BaxterPublishersResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::baxter_bridge::BaxterPublishersResponse> should match
// service_traits::DataType< ::baxter_bridge::BaxterPublishers >
template<>
struct DataType< ::baxter_bridge::BaxterPublishersResponse>
{
  static const char* value()
  {
    return DataType< ::baxter_bridge::BaxterPublishers >::value();
  }
  static const char* value(const ::baxter_bridge::BaxterPublishersResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // BAXTER_BRIDGE_MESSAGE_BAXTERPUBLISHERS_H
