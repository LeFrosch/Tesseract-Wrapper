#include "pch.h"
#include "ConversionTest.h"
#include "Conversion.h"

using namespace TesseractWrapper;

String^ TesseractWrapperTest::ConversionTest::ConvertString(String^ str)
{
	auto cha = StringToChar(str);

	return gcnew String(cha.get());
}

int TesseractWrapperTest::ConversionTest::ConvertBitmap(Bitmap^ map)
{
	auto pix = BitmapToPix(map);

	return pix.get()->w * pix.get()->h;
}
