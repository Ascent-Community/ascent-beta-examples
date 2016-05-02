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

#include "Body.h"
#include "ascent/Link.h"

class Spring : public asc::Module
{
public:
   asc::Link<Body> b0;
   asc::Link<Body> b1;
   double l0{}; // initial spring length (distance between masses)
   double k{}; // spring coefficient
   double f{}; // force

   Spring(size_t sim) : Spring(sim, b0, b1) {}
   Spring(size_t sim, const asc::Link<Body>& b0, const asc::Link<Body>& b1);

   void init();
   void update();
};