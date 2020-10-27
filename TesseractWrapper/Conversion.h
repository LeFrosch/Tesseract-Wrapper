#pragma once

#include "pch.h"

using namespace System;
using namespace System::Drawing;

namespace TesseractWrapper
{
	std::unique_ptr<char, void(*)(char*)> StringToChar(String^ str);

	std::unique_ptr<Pix, void(*)(Pix*)> BitmapToPix(Bitmap^ image);
}