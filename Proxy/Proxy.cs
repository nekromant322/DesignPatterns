using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace proxy
{
    class Proxy : Picture
    {
        String fileName;
        RealPicture real;
        public Proxy(String fileName)
        {
            this.fileName = fileName;
        }
        public Image GetImage()
        {
            if (real == null)
            {
                real = new RealPicture(fileName);
            }
            return real.GetImage();
        }
    }
}
