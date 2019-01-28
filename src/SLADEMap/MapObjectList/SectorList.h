#pragma once

#include "MapObjectList.h"
#include "SLADEMap/MapObject/MapSector.h"

class SectorList : public MapObjectList<MapSector>
{
public:
	// MapObjectList overrides
	void clear() override;
	void add(MapSector* sector) override;
	void remove(unsigned index) override;

	MapSector*         atPos(Vec2f point) const;
	BBox               allSectorBounds() const;
	void               initPolygons();
	void               initBBoxes();
	void               putAllWithId(int id, vector<MapSector*>& list) const;
	vector<MapSector*> allWithId(int id) const;
	MapSector*         firstWithId(int id) const;
	int                firstFreeId() const;

	void clearTexUsage() const { usage_tex_.clear(); }
	void updateTexUsage(const string& tex, int adjust) const { usage_tex_[tex.Upper()] += adjust; }
	int  texUsageCount(const string& tex) const { return usage_tex_[tex.Upper()]; }

private:
	mutable std::map<string, int> usage_tex_;
};
