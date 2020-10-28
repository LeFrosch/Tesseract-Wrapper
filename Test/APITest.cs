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
            using var reader = new ImageReader(@"..\bin", "eng");

            reader.SetPageSegMode(PageSegMode.PSM_SPARSE_TEXT);

            using (var image = new Bitmap(@"..\bin\testImage0.jpg"))
                reader.SetImage(image);

            Assert.IsTrue(reader.GetText().Contains("Countries Arranged by Geographical Location"));
        }
    }
}
