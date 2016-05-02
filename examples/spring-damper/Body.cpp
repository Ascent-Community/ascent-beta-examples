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

using namespace asc;

Body::Body(size_t sim) : Module(sim)
{
#define ascNS Body
   ascModule(Body)
   ascVar(s)
   ascVar(v)
   ascVar(a)
   ascVar(m)
   ascVar(f)

   addIntegrator(s, v);
   addIntegrator(v, a);
}

void Body::update()
{
   if (m != 0.0)
      a = f / m;
}

void Body::reset()
{
   f = 0.0;
}