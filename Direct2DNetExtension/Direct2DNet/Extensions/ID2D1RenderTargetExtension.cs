using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using D2DNet.Direct2DNet;

namespace D2DNet.Direct2DNet.Extensions
{
    public static class ID2D1RenderTargetExtension
    {
        public static async Task<int> EndDrawAsync(this ID2D1RenderTarget obj)
        {
            int hr = await Task.Run(obj.EndDraw).ConfigureAwait(false);
            return hr;
        }
    }
}
