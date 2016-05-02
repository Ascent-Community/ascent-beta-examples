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

#include "Control.h"

Control::Control(size_t sim) : asc::Module(sim),
   error(sim)
{
   addIntegrator(x, xd);
   addIntegrator(xd, xdd);

#define ascNS Control
   ascVar(x)
   ascVar(x_target)
}

void Control::update()
{
   xdd = -2.0*zeta*wn*xd - wn*wn*x + f / m; // This may seem simpler than the Spring-Damper example, but realize this is far less flexible.
}

void Control::postcalc()
{
   error.push_back(x_target - x);

   f = Kp*error.back() + Ki * error.integral() + Kd*error.derivative();
}