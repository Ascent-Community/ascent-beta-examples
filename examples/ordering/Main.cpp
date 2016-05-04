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

#include "Object.h"

#include "ascent\integrators\Euler.h"

int main()
{
   asc::integrator<asc::Euler>(0); // Use Euler integration for ordering examples so that there is only one update call per time step.

   asc::Link<Object> a(0);
   a.name("a");
   asc::Link<Object> b(0);
   b.name("b");
   asc::Link<Object> c(0);
   c.name("c");

   // Uncomment example to test:

   // Should run c, b, a
   //a->linked = b;
   //b->linked = c;

   // Circular dependency
   //a->linked = b;
   //b->linked = c;
   //c->linked = a;

   // Constraint conflict example (see Ascent Wiki article: Mixed Ordering Conflicts https://github.com/AnyarInc/ascent/wiki/Mixed-Ordering-Conflicts)
   //a->linked = b;
   //b->linked = c;
   //a->runBefore(c);

   // Should run a, c, b
   //a->linked = b;
   //b->linked = c;
   //a->runBefore(b, c);

   // Should run c, b, a
   //a->linked = b;
   //b->linked = c;
   //c->linked = a;
   //c->runBefore(a);

   // Two valid orderings: a, b, c or b, a, c
   //a->linked = b;
   //b->linked = c;
   //a->runBefore(c);
   //b->runBefore(c);

   // Should run a, b, c
   //a->linked = c;
   //a->runBefore(b);
   //b->runBefore(c);

   a->run(1.0, 1.0);

   return 0;
}