using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using D2DNet.Direct2DNet;

namespace D2DNet.Direct2DNet.Extensions
{
    public static class D2DImageLoaderExtension
    {
        public static async Task<ID2D1Bitmap> LoadBitmapFromFileAsync(this D2DImageLoader loader,
            ID2D1RenderTarget renderTarget, string filePath)
        {
            ID2D1Bitmap bitmap = await Task.Run(() =>
            {
                return loader.LoadBitmapFromFile(renderTarget, filePath);
            }).ConfigureAwait(false);

            return bitmap;
        }
    }
}
