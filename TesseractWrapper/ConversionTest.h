#pragma once

#include "pch.h"

using namespace System;
using namespace System::Drawing;

namespace TesseractWrapperTest
{
	public ref class ConversionTest
	{
	public:
		static String^ ConvertString(String^ str);

		static int ConvertBitmap(Bitmap^ map);
	};
}
