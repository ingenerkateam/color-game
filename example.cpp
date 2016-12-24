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
	int unsigned color;

    char mess[100] = "";
    sprintf(mess, data::Msg::findMe, 1, 2);
    txMessageBox (mess, data::Msg::progName);

    int timeInMils = 0;
	char messfinish[100] = "";

	while(1)
    {
        color = txGetPixel(txMouseX(),txMouseY());
		if (color == data::Info::Vars::ary[1][2])
        {
			char mess1[100] = "";
			sprintf(mess1, data::Msg::findMe, 2, 3);
			txMessageBox(mess1, data::Msg::progName);
			color = NULL;
			while(1)
			{
				color = txGetPixel(txMouseX(), txMouseY());
				if (color == data::Info::Vars::ary[2][3])
				{
					sprintf(messfinish, data::Msg::scoreMsg, timeInMils);
					txMessageBox(messfinish, data::Msg::progName);
					exit(0);
				}
				timeInMils++;
				txSleep(1);
			}
        }
		timeInMils++;
		txSleep(1);
    }
}
