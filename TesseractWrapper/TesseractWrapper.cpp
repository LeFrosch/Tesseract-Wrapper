#include "pch.h"

#include "TesseractWrapper.h"
#include "TesseractException.h"
#include "Conversion.h"

TesseractWrapper::ImageReader::ImageReader(String^ dataPath, String^ language) 
    : ImageReader(dataPath, language, OCREngineMode::OEM_LSTM_ONLY)
{ }

TesseractWrapper::ImageReader::ImageReader(String^ dataPath, String^ language, OCREngineMode mode)
{
    auto ptrDataPath = StringToChar(dataPath);
    auto ptrLanguage = StringToChar(language);

    api = new tesseract::TessBaseAPI();

    int ret = api->Init(ptrDataPath.get(), ptrLanguage.get(), (tesseract::OcrEngineMode) mode);
    if (ret)
        throw gcnew TesseractException("Failed to initialize tesseract.", ret);
}

TesseractWrapper::ImageReader::~ImageReader()
{
    api->End();
    delete api;
}

String^ TesseractWrapper::ImageReader::Reade(Bitmap^ image)
{
    auto pix = BitmapToPix(image);
    if (!pix.get())
        throw gcnew TesseractException("Failed to read bit map.", -1);

    api->SetImage(pix.get());

    auto ptrOutText = api->GetUTF8Text();
    auto gcOutText = gcnew String(ptrOutText);

    delete[] ptrOutText;
    return gcOutText;
}
