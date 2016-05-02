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

#include "ascent/history/History.h"
#include "ascent/Link.h"

class Control : public asc::Module
{
public:
   double x{}, xd{}, xdd{}; // We are going to control a simple mass-spring-damper system: x'' + 2*zeta*wn*x' + wn*wn*x = f/m
   double x_target{}; // Desired x value

   double f{}; // force applied

   double m = 1.0; // mass
   double wn = sqrt(40); // Hz
   double zeta = 0.7;

   asc::History error; // History of the error.

   double Kp{}; // Proportional gain
   double Ki{}; // Integral gain
   double Kd{}; // Derivative gain

   Control(size_t sim);

protected:
   void update();

   void postcalc();
};