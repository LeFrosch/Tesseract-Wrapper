# Tesseract-Wrapper
This project provides an interface for .net core to use the [Tesseract c++ library](https://github.com/tesseract-ocr/tesseract). The wrapper was created with the amie of simplicity and ease of use use but I only needed some functionality, thus not all functions are wrapped.

# Usage
Create an instance of the ImageReader class. The datapath must be the name of the tessdata directory, the tessdata can be downloaded from [here](https://github.com/tesseract-ocr/tessdata_best) or [here](https://github.com/tesseract-ocr/tessdata). The language is (usually) an ISO 639-3 string, eg "eng".
```c#
using var reader = new ImageReader(@"path\to\tessdata", "language");
```
Afterwards just set the path to the image and call the GetText to read all text in the image.
```c#
using (var image = new Bitmap(@"path\to\image"))
    reader.SetImage(image);
    
var text = reader.GetText();
```

# Installation
This library is available on nuget. To install the x64 version use:
```
Install-Package TesseractWrapper64
```
To install the x86 version use:
```
Install-Package TesseractWrapper86
```
