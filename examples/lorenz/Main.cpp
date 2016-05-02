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

#include "Lorenz.h"

int main()
{
   Lorenz lorenz(0);
   lorenz.name<Lorenz>("lorenz"); // name for this module instance
   lorenz.x = Eigen::Vector3d(10.0, 1.0, 1.0); // initial conditions

   lorenz.track("t");
   lorenz.track("x");

   lorenz.run(0.01, 50.0); // time step and simulation end time

   lorenz.outputTrack();

   return 0;
}