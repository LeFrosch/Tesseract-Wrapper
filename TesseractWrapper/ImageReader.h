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
		/// <summary>
		/// Creates and initializes a tesseract::TessBaseAPI instance. If the initialization fails a
		/// TesseractException is thrown.
		/// </summary>
		/// <param name="dataPath">
		/// The datapath must be the name of the tessdata directory.
		/// </param>
		/// <param name="language">
		/// The language is (usually) an ISO 639-3 string, eg "eng". The 
		/// language may be a string of the form [~]&lt;lang&gt;[+[~]&lt;lang&gt;]* indicating that multiple 
		/// languages are to be loaded. Eg hin+eng will load Hindi and English. Languages may specify 
		/// internally that they want to be loaded with one or more other languages, so the ~sign is 
		/// available to override that. Eg if hin were set to load eng by default, then hin+~eng 
		/// would force loading only hin.The number of loaded languages is limited only by memory, 
		/// with the caveat that loading additional languages will impact both speedand accuracy, as 
		/// there is more work to do to decide on the applicable language, and there is more chance 
		/// of hallucinating incorrect words.
		/// </param>
		ImageReader(String^ dataPath, String^ language);
		/// <param name="mode">Whether to instantiate/load/run only the Tesseract part, only the Cube 
		/// part or both along with the combiner.</param>
		ImageReader(String^ dataPath, String^ language, OCREngineMode mode);
		~ImageReader();

		/// <summary>
		/// Set the current page segmentation mode. Defaults to PSM_SINGLE_BLOCK.
		/// </summary>
		void SetPageSegMode(PageSegMode mode);

		/// <summary>
		/// Return the current page segmentation mode.
		/// </summary>
		PageSegMode GetPageSegMode();

		/// <summary>
		/// Provide an image for Tesseract to recognize. Tesseract takes its own copy of the image, 
		/// so it needs not persist until after recognition. Also all recognition results get cleared, 
		/// and the rectangle is set to the full image, so it may be followed immediately by a GetText.
		/// Throws a TesseractException if the image could not be converted into the format required for 
		/// Tesseract.
		/// </summary>
		void SetImage(Bitmap^ image);

		/// <summary>
		/// The recognized text is returned. Call SetImage before calling this method. 
		/// </summary>
		String^ GetText();
	};
}
