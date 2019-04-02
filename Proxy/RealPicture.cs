using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace proxy
{
    class RealPicture : Picture
    {
        Image RealImage;
        public RealPicture(String fileName)
        {
            RealImage = Image.FromFile(fileName);
        }
        public Image GetImage()
        {
            return RealImage;
        }
    }
}
