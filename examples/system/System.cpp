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

System::System(size_t sim) : asc::Module(sim)
{
   // Set masses
   b0->m = 0.3;
   b1->m = 1.0;
   b2->m = 0.5;
   // b3 is fixed, leave its mass as 0.0

   // Set damping constants
   d0->c = 0.7;
   d1->c = 0.4;
   d2->c = 0.3;

   // Set spring constants
   s0->k = 100.0;
   s1->k = 200.0;
   s2->k = 50.0;
   s3->k = 125.0;
   s4->k = 225.0;
}