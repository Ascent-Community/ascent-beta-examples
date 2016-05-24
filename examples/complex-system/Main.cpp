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

#include "System.h"

int main()
{
   asc::Link<System> system(0);
   system.name("system");

   system->b0->v = 1.0; // Initial condition to get everything moving.

   system->track("t");
   system->track(system->b0, "s");
   system->track(system->b1, "s");
   system->track(system->b2, "s");
   system->track(system->b3, "s");

   system->run(0.01, 2.0);

   system->outputTrack();

   return 0;
}