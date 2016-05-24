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
   asc::Link<Spring> spring(sim);
   spring.name("spring");
   asc::Link<Damper> damper(sim);
   damper.name("damper");

   body1->s = 1.0; // initial position
   body1->v = 40.0; // initial velocity
   body1->m = 1.0; // mass
   spring->k = 2000.0; // spring constant
   damper->c = 5.0; // damping constant

   asc::Module tracker(0);
   tracker.name<asc::Module>("b0vsb1");
   tracker.track("t");
   tracker.track(body0, "s");
   tracker.track(body1, "s");

   chaiscript::ChaiScript& chai = spring->chai;

   try
   {
      chai("spring.b0 = body0;");
      chai("spring.b1 = body1;");
      chai("damper.b0 = body0;");
      chai("damper.b1 = body1;");

      chai("body1.s = 2.0;");
      chai("spring.run(0.01, 1.5);");
   }
   catch (const chaiscript::exception::eval_error& ee)
   {
      std::cout << ee.pretty_print() << '\n';
   }

   tracker.outputTrack();

   return 0;
}