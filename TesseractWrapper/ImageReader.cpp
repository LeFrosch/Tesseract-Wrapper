#include "pch.h"

#include "ImageReader.h"
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

void TesseractWrapper::ImageReader::SetPageSegMode(PageSegMode mode)
{
    api->SetPageSegMode((tesseract::PageSegMode) mode);
}

TesseractWrapper::PageSegMode TesseractWrapper::ImageReader::GetPageSegMode()
{
    return (PageSegMode) api->GetPageSegMode();
}

void TesseractWrapper::ImageReader::SetRectangle(int left, int top, int width, int height)
{
    // input validation
    if (left >= this->width - 1 || left < 0)
        throw gcnew TesseractException("The left offset of the rectangle needs to be smaller than the image width - 1 and bigger than 0.", 0);
    if (top >= this->height - 1 || top < 0)
        throw gcnew TesseractException("The top offset of the rectangle needs to be smaller than the image height - 1 and bigger than 0.", 0);

    if (width < 1)
        throw gcnew TesseractException("The rectangle width cannot be smaller than 1.", 0);
    if (height < 1)
        throw gcnew TesseractException("The rectangle height cannot be smaller than 1.", 0);

    // clamp the width and the hieght values
    if (left + width > this->width)
        width = this->width - left;
    if (top + height > this->height)
        height = this->height - top;

    api->SetRectangle(left, top, width, height);
}

void TesseractWrapper::ImageReader::SetImage(Bitmap^ image)
{
    if (image == nullptr)
        throw gcnew TesseractException("The image cannot be null.", 0);

    width = image->Width;
    height = image->Height;

    auto pix = BitmapToPix(image);
    if (!pix.get())
        throw gcnew TesseractException("Failed to read bit map.", -1);

    api->SetImage(pix.get());
}

String^ TesseractWrapper::ImageReader::GetText()
{
    auto ptrOutText = api->GetUTF8Text();
    auto gcOutText = gcnew String(ptrOutText);

    delete[] ptrOutText;
    return gcOutText;
}
