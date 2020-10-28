#pragma once

#include "pch.h"

using namespace System;

namespace TesseractWrapper
{
	/// <summary>
    /// Wrapper for the tesseract::OcrEngineMode enum.
    /// 
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
        /// Specify this mode to indicate that any of the other modes should be 
        /// automatically inferred from the variables in the language-specific config, 
        /// command-line configs, or if not specified in any of the above should be set 
        /// to the default OEM_TESSERACT_ONLY.
        /// </summary>
        OEM_DEFAULT                 = tesseract::OEM_DEFAULT
	};

    /// <summary>
    /// Wrapper for the tesseract::PageSegMode enum.
    /// 
    /// Possible modes for page layout analysis. These *must* be kept in order of 
    /// decreasing amount of layout analysis to be done, except for OSD_ONLY, so that 
    /// the inequality test macros below work.
    /// </summary>
    public enum class PageSegMode
    {
        /// <summary>
        /// Orientation and script detection only.
        /// </summary>
        PSM_OSD_ONLY                = tesseract::PSM_OSD_ONLY,
        /// <summary>
        /// Automatic page segmentation with orientation and script detection. (OSD)
        /// </summary>
        PSM_AUTO_OSD                = tesseract::PSM_AUTO_OSD,
        /// <summary>
        /// Automatic page segmentation, but no OSD, or OCR.
        /// </summary>
        PSM_AUTO_ONLY               = tesseract::PSM_AUTO_ONLY,
        /// <summary>
        /// Fully automatic page segmentation, but no OSD.
        /// </summary>
        PSM_AUTO                    = tesseract::PSM_AUTO,
        /// <summary>
        /// Assume a single column of text of variable sizes.
        /// </summary>
        PSM_SINGLE_COLUMN           = tesseract::PSM_SINGLE_COLUMN,
        /// <summary>
        /// Assume a single uniform block of vertically aligned text.
        /// </summary>
        PSM_SINGLE_BLOCK_VERT_TEXT  = tesseract::PSM_SINGLE_BLOCK_VERT_TEXT,
        /// <summary>
        /// Assume a single uniform block of text. (Default.)
        /// </summary>
        PSM_SINGLE_BLOCK            = tesseract::PSM_SINGLE_BLOCK,
        /// <summary>
        /// Treat the image as a single text line.
        /// </summary>
        PSM_SINGLE_LINE             = tesseract::PSM_SINGLE_LINE,
        /// <summary>
        /// Treat the image as a single word.
        /// </summary>
        PSM_SINGLE_WORD             = tesseract::PSM_SINGLE_WORD,
        /// <summary>
        /// Treat the image as a single word in a circle.
        /// </summary>
        PSM_CIRCLE_WORD             = tesseract::PSM_CIRCLE_WORD,
        /// <summary>
        /// Treat the image as a single character.
        /// </summary>
        PSM_SINGLE_CHAR             = tesseract::PSM_SINGLE_CHAR,
        /// <summary>
        /// Find as much text as possible in no particular order.
        /// </summary>
        PSM_SPARSE_TEXT             = tesseract::PSM_SPARSE_TEXT,
        /// <summary>
        /// Sparse text with orientation and script det.
        /// </summary>
        PSM_SPARSE_TEXT_OSD         = tesseract::PSM_SPARSE_TEXT_OSD,
        /// <summary>
        /// Treat the image as a single text line, bypassing hacks that are 
        /// Tesseract-specific.
        /// </summary>
        PSM_RAW_LINE                = tesseract::PSM_RAW_LINE
    };
}
