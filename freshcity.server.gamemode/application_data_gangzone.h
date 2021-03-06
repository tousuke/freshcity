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

#ifndef FRESHCITY_APPLICATION_DATA_GANGZONE
#define FRESHCITY_APPLICATION_DATA_GANGZONE

#include "application_data_profile.h"
#include <sampgdk/a_samp.h>

class GangZoneItem : public SaveableItem {
protected:
	boost::shared_ptr<GangZone> _zone;
	int _areaid, _triggerid;
	std::string _name;
	mongo::OID _owner;
	int _color;
	int _endtimerid, _timeouttimerid;
	mongo::OID _spawnpoint;

	struct TurfWarInfo {
		bool InWar;
		mongo::OID Attacker;
		int MemberDeath, EnemyKill;
		TurfWarInfo() : InWar(false), MemberDeath(0), EnemyKill(0) {}
	} _warinfo;

private:
	void _LoadOwnerData();
	void _InitArea();

public:
	GangZoneItem(const std::string& name);
	GangZoneItem(const mongo::BSONObj& data);
	GangZoneItem(const std::string& name, const mongo::OID& owner,
		const CoordinatePlane& min, const CoordinatePlane& max,
		const mongo::OID& spawnpoint, const Coordinate3D& trigger);
	~GangZoneItem();
	void SetName(const std::string& name);
	std::string GetName() const;
	void SetOwner(const mongo::OID& owner);
	mongo::OID GetOwner() const;
	GangZone& Get();
	void Redraw();
	bool StartWar(Profile& attacker);
	void CountEnemyKill();
	void CountMemberDeath();
	/* true = Attacker wins. */
	bool EndWar(bool causedbytimeout = false);
	int GetAreaID() const;
	bool InWar() const;
	mongo::OID GetAttacker() const;
	void MemberArrived();
	void SetSpawnPoint(const mongo::OID& waypointid);
	mongo::OID GetSpawnPoint() const;
};

enum GangZoneCreationStep {
	GANGZONE_CREATE_MIN = 1,
	GANGZONE_CREATE_MAX = 2,
	GANGZONE_CREATE_SPAWNPOINT = 4,
	GANGZONE_CREATE_TRIGGER = 8
};

struct GangZoneCreationInfo {
	GangZoneCreationInfo(const std::string& name) : name(name), step(0) {}
	std::string name;
	CoordinatePlane min, max;
	Coordinate5D spawnpoint;
	Coordinate3D trigger;
	unsigned int step;
};

#endif
