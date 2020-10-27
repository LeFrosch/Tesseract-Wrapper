using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Drawing;
using System.IO;
using TesseractWrapper;

namespace Test
{
    [TestClass]
    public class APITest
    {
        [TestMethod]
        public void ReadingTest()
        {
            using var reader = new ImageReader(@"..\bin", "eng", OCREngineMode.);

            Console.WriteLine(reader.Reade(new Bitmap(@"..\bin\testImage.jpg")));
        }
    }
}
