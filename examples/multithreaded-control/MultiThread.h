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

#include "Control.h"

#include <thread>

class MultiThread
{
public:
   std::vector<asc::Link<Control>> modules;

   MultiThread()
   {
      for (size_t i = 0; i < 4; ++i) // i is the thread/simulator number
      {
         asc::Link<Control> c(i);
         c->name<Control>("control" + std::to_string(i));

         c->Kp = 100.0 * (1 + i); // Each thread will run a separate proportional gain.
         c->Ki = 300.0;
         c->Kd = 10.0;

         c->x_target = 1.0;

         c->track("t");
         c->track("x");
         c->track("x_target");

         modules.push_back(c);
      }
   }

   void compute(asc::Link<Control>& control, const double dt, const double tend)
   {
      control->run(dt, tend);
      control->outputTrack();
      std::cout << control->name() << " finished\n";
   }

   void run(const double dt, const double tend)
   {
      std::vector<std::thread> threads;

      for (asc::Link<Control>& c : modules)
         threads.push_back(std::thread([&] { compute(c, dt, tend); }));

      for (std::thread& t : threads)
         t.join();
   }
};