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

#include "TXLib.h"
#include "stdlib.h"
#include "data.h"
#include "windows.h"

int main()
{
    txCreateWindow(400,225);
    HDC colorTable = txLoadImage("colors.bmp");
    txBitBlt(txDC(), 0, 0, 400, 225, colorTable, 0, 0);
	int unsigned color;

    // Ignore C4244 warning!
	int unsigned xTable = data::rnd(3);
    int unsigned yTable = data::rnd(3);
	// =====================

    char mess[100] = "";
    sprintf_s(mess, "Find color in position %d, %d", xTable + 1, yTable + 1);
    txMessageBox (mess, "Color-Game");

    int timeInMils = 0;
	char messfinish[100] = "";

	while(1)
    {
        color = txGetPixel(txMouseX(),txMouseY());
        if (color == data::ary[xTable][yTable])
        {
            sprintf_s(messfinish, data::scoreMsg, timeInMils);
            txMessageBox (messfinish, data::progName);
			exit(0);
        }
		timeInMils++;
		txSleep(1);
    }
}
