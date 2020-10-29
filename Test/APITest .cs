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
        public void SimpleReadingTest()
        {
            using var reader = new ImageReader(@"..\bin", "eng");

            reader.SetPageSegMode(PageSegMode.PSM_SPARSE_TEXT);

            using (var image = new Bitmap(@"..\bin\testImage0.jpg"))
                reader.SetImage(image);

            Assert.IsTrue(reader.GetText().Contains("Countries Arranged by Geographical Location"));
        }

        [TestMethod]
        public void RectReadingTest()
        {
            using var reader = new ImageReader(@"..\bin", "eng");

            using (var image = new Bitmap(@"..\bin\testImage1.jpg"))
                reader.SetImage(image);

            reader.SetPageSegMode(PageSegMode.PSM_SINGLE_COLUMN);
            reader.SetRectangle(10, 10, 90, 55);
            Assert.IsTrue(reader.GetText().Contains("RAM:\n*exists*"));

            reader.SetPageSegMode(PageSegMode.PSM_SINGLE_LINE);
            reader.SetRectangle(100, 290, 170, 20);
            Assert.IsTrue(reader.GetText().Contains("took that"));
        }
    }
}
