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

#include "Approx.h"
#include "Pendulum.h"

int main()
{
   const size_t sim = 0;

   constexpr double pi = 3.14159265358979323846;
   constexpr double theta = 30.0*pi / 180.0; // initial condition (30 degrees, converted to radians)

   // Small angle approximation
   asc::Link<Approx> approx(sim);
   approx.name("approximated");

   approx->theta = theta;
   approx->length = 1.0;

   // Nonlinear solution
   asc::Link<Pendulum> pendulum(sim);
   pendulum.name("pendulum");

   pendulum->theta = theta;
   pendulum->length = 1.0;

   pendulum->track("t");
   pendulum->track(approx, "theta");
   pendulum->track("theta");

   pendulum->run(0.01, 10.0);

   pendulum->outputTrack();

   return 0;
}