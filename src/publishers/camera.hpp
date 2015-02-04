/*
 * Copyright 2015 Aldebaran
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef PUBLISHER_CAMERA_HPP
#define PUBLISHER_CAMERA_HPP

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <qi/anyobject.hpp>

#include "publisher_base.hpp"

namespace alros
{
namespace publisher
{

class CameraPublisher : public BasePublisher<CameraPublisher>
{
public:
  CameraPublisher( const std::string& name, const std::string& topic, float frequency, const qi::AnyObject& p_video);

  void publish();

  void reset( ros::NodeHandle& nh );

  inline bool isSubscribed() const
  {
    if (is_initialized_ == false) return false;
    return pub_.getNumSubscribers() > 0;
  }

private:
  //image_transport::ImageTransport it_;
  image_transport::Publisher pub_;

  qi::AnyObject p_video_;
  sensor_msgs::ImagePtr msg_;
  std::string handle_;
};

} //publisher
} //alros


#endif
