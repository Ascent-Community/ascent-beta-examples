// Copyright (c) 2015 - 2016 Anyar, Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//      http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "ascent/Link.h"
#include "Eigen/Dense"

class Lorenz : public asc::Module
{
public:
   Eigen::Vector3d x = Eigen::Vector3d::Zero();
   Eigen::Vector3d xd = Eigen::Vector3d::Zero(); // derivative of x

   const double sigma = 10.0;
   const double R = 28.0;
   const double b = 8.0 / 3.0;

   Lorenz(size_t sim);

protected:
   void update();
};