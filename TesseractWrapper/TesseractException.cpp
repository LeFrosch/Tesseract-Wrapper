#include "pch.h"
#include "TesseractException.h"

TesseractWrapper::TesseractException::TesseractException(String^ cause, int error) : Exception(cause)
{
    errorCode = error;
}

int TesseractWrapper::TesseractException::GetErrorCode()
{
    return errorCode;
}
