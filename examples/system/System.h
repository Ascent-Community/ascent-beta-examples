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

#include "Damper.h"
#include "Spring.h"

class System : public asc::Module
{
public:
   asc::Link<Body> b0{ sim }, b1{ sim }, b2{ sim }, b3{ sim };
   asc::Link<Damper> d0{ sim, b0, b1 }, d1{ sim, b0, b2 }, d2{ sim, b2, b3 };
   asc::Link<Spring> s0{ sim, b0, b1 }, s1{ sim, b1, b3 }, s2{ sim, b0, b3 }, s3{ sim, b1, b2 }, s4{ sim, b2, b3 };

   System(size_t sim);
};