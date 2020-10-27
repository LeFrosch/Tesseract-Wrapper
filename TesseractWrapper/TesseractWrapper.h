#pragma once

#include "pch.h"
#include "TesseractSettings.h"

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
		ImageReader(String^ dataPath, String^ language, OCREngineMode mode);
		~ImageReader();

		String^ Reade(Bitmap^ image);
	};
}
