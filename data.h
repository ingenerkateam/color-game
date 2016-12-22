/*
	<lazers>
	Copyright (C) <2016>  <NeverMine17>

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "TXLib.h"
class data
{
public:
	class Info
	{
	public:;
		   class Func
		   {
		   public:;
				  static int unsigned rnd(int num);
		   };

		   class Vars
		   {
		   public:;
			   static int unsigned ary[3][7];
			   static HDC colorTable;
			   class Table
			   {
			   public:;
				   static int unsigned x;
				   static int unsigned y;
			   };
			   static int unsigned windowSizes[2];
			   static int unsigned tableSizes[2];
		   };
	};
	class Msg
	{
	public:;
		static const char* progName;
		static const char* scoreMsg;
		static const char* youFindIt;
	};
};

