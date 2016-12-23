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

int main()
{
    txCreateWindow(data::Info::Vars::windowSizes[0], data::Info::Vars::windowSizes[1]);
    
    txBitBlt(txDC(), 0, 0, data::Info::Vars::tableSizes[0], data::Info::Vars::tableSizes[1], data::Info::Vars::colorTable, 0, 0);
	int unsigned color;

    char mess[100] = "";
    sprintf_s(mess, "Find color in position %d, %d", data::Info::Vars::Table::x + 1, data::Info::Vars::Table::y + 1);
    txMessageBox (mess, "Color-Game");

    int timeInMils = 0;
	char messfinish[100] = "";

	while(1)
    {
        color = txGetPixel(txMouseX(),txMouseY());
        if (color == data::Info::Vars::ary[data::Info::Vars::Table::x][data::Info::Vars::Table::y])
        {
            sprintf_s(messfinish, data::Msg::scoreMsg, timeInMils);
            txMessageBox (messfinish, data::Msg::progName);
			exit(0);
        }
		timeInMils++;
		txSleep(1);
    }
}
