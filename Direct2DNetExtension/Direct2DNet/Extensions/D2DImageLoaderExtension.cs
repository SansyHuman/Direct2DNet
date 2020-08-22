using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using D2DNet.Direct2DNet;
using D2DNet.WICNet;

namespace D2DNet.Direct2DNet.Extensions
{
    public static class D2DImageLoaderExtension
    {
        public static async Task<ID2D1Bitmap> LoadBitmapFromFileAsync(
            this D2DImageLoader loader,
            ID2D1RenderTarget renderTarget,
            string filePath,
            Guid? format = null,
            WICBitmapDitherType dither = WICBitmapDitherType.None,
            double alphaThresholdPercent = 0,
            WICBitmapPaletteType paletteTranslate = WICBitmapPaletteType.Custom,
            IWICPalette palette = null)
        {
            if (!format.HasValue)
                format = PixelFormatGUID.Format32bppPBGRA;

            ID2D1Bitmap bitmap = await Task.Run(() =>
            {
                return loader.LoadBitmapFromFile(
                    renderTarget,
                    filePath,
                    format,
                    dither,
                    alphaThresholdPercent,
                    paletteTranslate,
                    palette
                    );
            }).ConfigureAwait(false);

            return bitmap;
        }
    }
}
