#pragma once

#include "pch.h"

using namespace System;

namespace TesseractWrapper
{
	/// <summary>
	/// When Tesseract/Cube is initialized we can choose to instantiate/load/
    /// only the Tesseract part, only the Cube part or both along with the combiner.
    /// The preference of which engine to use is stored in tessedit_ocr_engine_mode.
	/// </summary>
	public enum class OCREngineMode 
	{ 
        /// <summary>
        /// Run Tesseract only - fastest
        /// </summary>
        [Obsolete()]
        OEM_TESSERACT_ONLY          = tesseract::OEM_TESSERACT_ONLY,
        /// <summary>
        /// Run just the LSTM line recognizer.
        /// </summary>
        OEM_LSTM_ONLY               = tesseract::OEM_LSTM_ONLY,
        /// <summary>
        /// Run the LSTM recognizer, but allow to Tesseract when things get difficult.
        /// </summary>
        [Obsolete()]
        OEM_TESSERACT_LSTM_COMBINED = tesseract::OEM_TESSERACT_LSTM_COMBINED,
        /// <summary>
        /// Specify this mode when calling <see cref="ImageReader(String, String, OCREngineMode)"/> 
        /// to indicate that any of the above modes should be automatically inferred from the variables 
        /// in the language-specific config, command-line configs, or if not specified in any of the 
        /// above should be set to the default OEM_TESSERACT_ONLY.
        /// </summary>
        OEM_DEFAULT                 = tesseract::OEM_DEFAULT
	};
}
