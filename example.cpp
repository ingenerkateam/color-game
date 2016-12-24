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
#pragma warning(disable : 4996) 
#include "TXLib.h"
#include "stdlib.h"
#include "data.h"
#include <iostream>

int main()
{
    txCreateWindow(data::Info::Vars::windowSizes[0], data::Info::Vars::windowSizes[1]);

	HDC colorTable = txLoadImage("colors.bmp");
    txBitBlt(txDC(), 0, 0, data::Info::Vars::tableSizes[0], data::Info::Vars::tableSizes[1], colorTable, 0, 0);

	txMessageBox(data::Msg::findMe, data::Msg::progName);

	int timeInMils = 0;
	char messfinish[100] = "";
	COLORREF color;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			while (1)
			{
				color = txGetPixel(txMouseX(), txMouseY());
				if (color == data::Info::Vars::ary[x][y])
				{
					break;
				}
				timeInMils++;
				txSleep(1);
			}
		}
	}
	sprintf(messfinish, data::Msg::scoreMsg, timeInMils);
	txMessageBox(messfinish, data::Msg::progName);
	exit(0);
}
