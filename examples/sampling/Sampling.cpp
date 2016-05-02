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

#include "Sampling.h"

using namespace std;

Sampling::Sampling(size_t sim) : asc::Module(sim)
{
   addIntegrator(x, xd);
}

void Sampling::update()
{
   cout << "update()-----" << '\n';
   cout << "time: " << t << '\n';

   xd = cos(t); // integrated xd will be sin(t)

   if (sample())
      cout << "x at first pass of integration step: " << x << '\n';
   else
      cout << "x: " << x << '\n';

   if (sample(0.13) && !first_update) // sample() will always return true when t == 0.0, we use !first_update here to exclude printing the initial condition
      cout << "x every 0.13: " << x << '\n';

   cout << '\n';
}

void Sampling::report()
{
   cout << "report()*****" << '\n';
   cout << "time: " << t << '\n';
   cout << "analytical sin(t): " << sin(t) << '\n';
   cout << "computed x: " << x << '\n' << '\n';
}