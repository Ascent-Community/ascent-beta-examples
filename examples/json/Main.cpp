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

#include "ascent/io/JsonAPI.h"

#include "Body.h"
#include "Damper.h"
#include "Spring.h"

int main()
{
   const size_t sim = 0;

   asc::Link<Body> body0(sim);
   asc::Link<Body> body1(sim);
   body0.name("body0");
   body1.name("body1");

   asc::Link<Spring> spring(sim, body0, body1);
   spring.name("spring");

   asc::Link<Damper> damper(sim, body0, body1);
   damper.name("damper");

   damper->c = 5.0; // damping constant

   asc::Module tracker(0);
   tracker.name<asc::Module>("b0vsb1");
   tracker.track("t");
   tracker.track(body0, "s");
   tracker.track(body1, "s");

   jsoncons::json output = asc::JsonAPI::ioFile("../../../examples/json/input.json"); // Initialize spring and mass values from json input. Get damper constant value back.

   std::cout << jsoncons::pretty_print(output) << '\n';

   spring->run(0.01, 1.5);

   tracker.outputTrack();

   return 0;
}