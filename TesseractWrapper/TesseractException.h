#pragma once

#include "pch.h"

using namespace System;

namespace TesseractWrapper
{
	public ref class TesseractException : public Exception
	{
	private:
		int errorCode;

	public:
		TesseractException(String^ cause, int error);

		int GetErrorCode();
	};
}
