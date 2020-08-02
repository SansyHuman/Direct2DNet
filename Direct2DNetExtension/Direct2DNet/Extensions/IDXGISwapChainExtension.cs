using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using D2DNet.DXGINet;

namespace D2DNet.Direct2DNet.Extensions
{
    public static class IDXGISwapChainExtension
    {
        public static async Task<int> PresentAsync(this IDXGISwapChain obj, uint syncInterval, DXGI_PRESENT flags)
        {
            int result = await Task.Run(() =>
            {
                return obj.Present(syncInterval, flags);
            }).ConfigureAwait(false);

            return result;
        }
    }
}
