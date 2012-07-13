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

#include "application_database.h"
#include "application_gamemode_manager_profile.h"

bool ProfileManager::Add(int playerid) {
	if(IsExist(playerid)) return false;
	_players.insert(std::make_pair(playerid,
		boost::shared_ptr<Profile>(new Profile(playerid, GetPlayerName(playerid)))));
	return true;
}

bool ProfileManager::IsExist(int playerid) const {
	return _players.find(playerid) != _players.end();
}

bool ProfileManager::Remove(int playerid) {
	ProfileMap::const_iterator iter(_players.find(playerid));
	if(iter == _players.end()) return false;
	_players.erase(iter);
	return true;
}

Profile& ProfileManager::Get(int playerid) {
	return *_players.at(playerid).get();
}

Profile& ProfileManager::operator[](int playerid) {
	return Get(playerid);
}

ProfileManager& ProfileManager::GetInstance() {
	static ProfileManager inst;
	return inst;
}