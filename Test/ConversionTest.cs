using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Drawing;

namespace Test
{
    [TestClass]
    public class ConversionTest
    {
        [TestMethod]
        public void TestStringToChar()
        {
            for (var i = 0; i < 100000; i++)
            {
                var hash = i.GetHashCode().ToString();
                var test = TesseractWrapperTest.ConversionTest.ConvertString(hash);

                Assert.AreEqual(hash, test);
            }
        }

        [TestMethod]
        public void TestBitmapToPix()
        {
            for (var i = 1; i <= 100; i++)
            {
                using var map = new Bitmap(i * 15, i * 10);

                var widhtHeight = TesseractWrapperTest.ConversionTest.ConvertBitmap(map);

                Assert.AreEqual(widhtHeight, i * 15 * i * 10);
            }
        }
    }
}
