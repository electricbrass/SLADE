
// -----------------------------------------------------------------------------
// SLADE - It's a Doom Editor
// Copyright(C) 2008 - 2017 Simon Judd
//
// Email:       sirjuddington@gmail.com
// Web:         http://slade.mancubus.net
// Filename:    SideList.cpp
// Description: A (non-owning) list of map sides. Includes std::vector-like API
//              for accessing items and some misc functions to get info about
//              the contained items.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110 - 1301, USA.
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
//
// Includes
//
// -----------------------------------------------------------------------------
#include "Main.h"
#include "SideList.h"


// -----------------------------------------------------------------------------
//
// SideList Class Functions
//
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
// Clears the list (and texture usage)
// -----------------------------------------------------------------------------
void SideList::clear()
{
	usage_tex_.clear();
	MapObjectList::clear();
}

// -----------------------------------------------------------------------------
// Adds [side] to the list and updates texture usage
// -----------------------------------------------------------------------------
void SideList::add(MapSide* side)
{
	// Update texture counts
	usage_tex_[side->tex_upper_.Upper()] += 1;
	usage_tex_[side->tex_middle_.Upper()] += 1;
	usage_tex_[side->tex_lower_.Upper()] += 1;

	MapObjectList::add(side);
}

// -----------------------------------------------------------------------------
// Removes [side] from the list and updates texture usage
// -----------------------------------------------------------------------------
void SideList::remove(unsigned index)
{
	if (index >= objects_.size())
		return;

	// Update texture counts
	usage_tex_[objects_[index]->tex_upper_.Upper()] -= 1;
	usage_tex_[objects_[index]->tex_middle_.Upper()] -= 1;
	usage_tex_[objects_[index]->tex_lower_.Upper()] -= 1;

	MapObjectList::remove(index);
}
