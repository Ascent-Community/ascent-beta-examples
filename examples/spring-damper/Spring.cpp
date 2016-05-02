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

#include "Spring.h"

Spring::Spring(size_t sim, const asc::Link<Body>& b0, const asc::Link<Body>& b1) : asc::Module(sim), b0(b0), b1(b1)
{
#define ascNS Spring
   ascModule(Spring)
   ascVar(k)
   ascLink(b0)
   ascLink(b1)
}

void Spring::init()
{
   runBefore(b0, b1);

   l0 = b1->s - b0->s;
}

void Spring::update()
{
   double ds = l0 + b0->s - b1->s;
   f = k*ds;

   b0->f -= f;
   b1->f += f;
}