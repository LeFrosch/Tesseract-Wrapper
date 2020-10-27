#pragma once

#include "pch.h"

using namespace System;
using namespace System::Drawing;

namespace TesseractWrapper 
{
	public ref class ImageReader : IDisposable
	{
	private:
		tesseract::TessBaseAPI* api;

	public:
		ImageReader(String^ dataPath, String^ language);
		~ImageReader();

		String^ Reade(Bitmap^ image);
	};
}
