/*
 * Copyright 2012 TennenColl
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FRESHCITY_APPLICATION_CONFIG
#define FRESHCITY_APPLICATION_CONFIG

#include <boost/property_tree/ptree.hpp>

void ReloadConfig();
boost::property_tree::ptree& GetConfig();

#define CONFIG_STRING(path) GetConfig().get<std::string>(path)
#define CONFIG_DOUBLE(path) GetConfig().get<double>(path)
#define CONFIG_FLOAT(path) GetConfig().get<float>(path)
#define CONFIG_INT(path) GetConfig().get<int>(path)
#define CONFIG_LONG(path) GetConfig().get<long>(path)
#define CONFIG_BOOLEAN(path) GetConfig().get<bool>(path)

#endif
