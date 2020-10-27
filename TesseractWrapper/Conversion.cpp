#include "pch.h"
#include "Conversion.h"

using namespace System::IO;
using namespace System::Drawing::Imaging;
using namespace System::Runtime::InteropServices;

std::unique_ptr<char, void(*)(char*)> TesseractWrapper::StringToChar(String^ str)
{
    return std::unique_ptr<char, void(*)(char*)>(
        (char*)(void*)Marshal::StringToHGlobalAnsi(str),
        [](char* cStr) 
        {
            Marshal::FreeHGlobal((System::IntPtr)(void*)cStr);
        }
    );
}

std::unique_ptr<Pix, void(*)(Pix*)> TesseractWrapper::BitmapToPix(Bitmap^ image)
{
    MemoryStream^ stream = gcnew MemoryStream();
    image->Save(stream, ImageFormat::Bmp);

    array<unsigned char>^ gcArray = stream->ToArray();

    std::vector<unsigned char> buffer(gcArray->Length);
    Marshal::Copy(gcArray, 0, IntPtr(&buffer[0]), gcArray->Length);

    stream->Close();

    return std::unique_ptr<Pix, void(*)(Pix*)>(
        pixReadMemBmp(&buffer[0], buffer.size()),
        [](Pix* pix)
        {
            pixDestroy(&pix);
        }
    );
}
