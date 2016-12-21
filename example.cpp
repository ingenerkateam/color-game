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

int main()
{
    int ary[3][7] =  {
		{ RGB(164,196,0), RGB(96,169,23)  , RGB(0,138,0)    , RGB(0,171,169)  , RGB(27,161,226), RGB(0,80,239) , RGB(106,0,255) },
		{ RGB(170,0,255), RGB(244,114,208), RGB(216,0,115)  , RGB(162,0,37)   , RGB(229,20,0)  , RGB(250,104,0), RGB(240,163,10)},
		{ RGB(227,200,0), RGB(130,90,44)  , RGB(109,135,100), RGB(100,118,135), RGB(118,96,138), RGB(160,82,45), RGB(148,70,34) }
    };
    txCreateWindow(400,225);
    HDC colorTable = txLoadImage("colors.bmp");
    txBitBlt(txDC(), 0, 0, 400, 225, colorTable, 0, 0);
    COLORREF color;

    txMessageBox ("Найди мне цвет в позиции 1,1", "Color-Game");

    int score = 0;

    while(1)
    {
        color = txGetPixel(txMouseX(),txMouseY());
        if (color == ary[1][1])
        {
            cout << "You find it with score: " << score;
            break;
        }
        score++;
    }


}
