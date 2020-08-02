using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D2DNet.Extensions
{
    public static class DirectXHelper
    {
        public static int CreateComObject<IOut>(
            Func<IOut> callback,
            out IOut obj
            ) where IOut : class, IUnknown
        {
            try
            {
                obj = callback.Invoke();
                return 0;
            }
            catch (Exception e)
            {
#if DEBUG
                DirectX.PrintDebugMessage(e.Message);
                DirectX.PrintDebugMessage(e.StackTrace);
#endif

                obj = null;
                return e.HResult;
            }
        }

        public static int CreateComObject<T1, IOut>(
            Func<T1, IOut> callback,
            in T1 arg1,
            out IOut obj
            ) where IOut : class, IUnknown
        {
            try
            {
                obj = callback.Invoke(arg1);
                return 0;
            }
            catch (Exception e)
            {
#if DEBUG
                DirectX.PrintDebugMessage(e.Message);
                DirectX.PrintDebugMessage(e.StackTrace);
#endif

                obj = null;
                return e.HResult;
            }
        }

        public static int CreateComObject<T1, T2, IOut>(
            Func<T1, T2, IOut> callback,
            in T1 arg1,
            in T2 arg2,
            out IOut obj
            ) where IOut : class, IUnknown
        {
            try
            {
                obj = callback.Invoke(arg1, arg2);
                return 0;
            }
            catch (Exception e)
            {
#if DEBUG
                DirectX.PrintDebugMessage(e.Message);
                DirectX.PrintDebugMessage(e.StackTrace);
#endif

                obj = null;
                return e.HResult;
            }
        }

        public static int CreateComObject<T1, T2, T3, IOut>(
            Func<T1, T2, T3, IOut> callback,
            in T1 arg1,
            in T2 arg2,
            in T3 arg3,
            out IOut obj
            ) where IOut : class, IUnknown
        {
            try
            {
                obj = callback.Invoke(arg1, arg2, arg3);
                return 0;
            }
            catch (Exception e)
            {
#if DEBUG
                DirectX.PrintDebugMessage(e.Message);
                DirectX.PrintDebugMessage(e.StackTrace);
#endif

                obj = null;
                return e.HResult;
            }
        }

        public static int CreateComObject<T1, T2, T3, T4, IOut>(
            Func<T1, T2, T3, T4, IOut> callback,
            in T1 arg1,
            in T2 arg2,
            in T3 arg3,
            in T4 arg4,
            out IOut obj
            ) where IOut : class, IUnknown
        {
            try
            {
                obj = callback.Invoke(arg1, arg2, arg3, arg4);
                return 0;
            }
            catch (Exception e)
            {
#if DEBUG
                DirectX.PrintDebugMessage(e.Message);
                DirectX.PrintDebugMessage(e.StackTrace);
#endif

                obj = null;
                return e.HResult;
            }
        }

        public static int CreateComObject<T1, T2, T3, T4, T5, IOut>(
            Func<T1, T2, T3, T4, T5, IOut> callback,
            in T1 arg1,
            in T2 arg2,
            in T3 arg3,
            in T4 arg4,
            in T5 arg5,
            out IOut obj
            ) where IOut : class, IUnknown
        {
            try
            {
                obj = callback.Invoke(arg1, arg2, arg3, arg4, arg5);
                return 0;
            }
            catch (Exception e)
            {
#if DEBUG
                DirectX.PrintDebugMessage(e.Message);
                DirectX.PrintDebugMessage(e.StackTrace);
#endif

                obj = null;
                return e.HResult;
            }
        }

        public static int CreateComObject<T1, T2, T3, T4, T5, T6, IOut>(
            Func<T1, T2, T3, T4, T5, T6, IOut> callback,
            in T1 arg1,
            in T2 arg2,
            in T3 arg3,
            in T4 arg4,
            in T5 arg5,
            in T6 arg6,
            out IOut obj
            ) where IOut : class, IUnknown
        {
            try
            {
                obj = callback.Invoke(arg1, arg2, arg3, arg4, arg5, arg6);
                return 0;
            }
            catch (Exception e)
            {
#if DEBUG
                DirectX.PrintDebugMessage(e.Message);
                DirectX.PrintDebugMessage(e.StackTrace);
#endif

                obj = null;
                return e.HResult;
            }
        }


        public static int CreateComObject<T1, T2, T3, T4, T5, T6, T7, IOut>(
            Func<T1, T2, T3, T4, T5, T6, T7, IOut> callback,
            in T1 arg1,
            in T2 arg2,
            in T3 arg3,
            in T4 arg4,
            in T5 arg5,
            in T6 arg6,
            in T7 arg7,
            out IOut obj
            ) where IOut : class, IUnknown
        {
            try
            {
                obj = callback.Invoke(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
                return 0;
            }
            catch (Exception e)
            {
#if DEBUG
                DirectX.PrintDebugMessage(e.Message);
                DirectX.PrintDebugMessage(e.StackTrace);
#endif

                obj = null;
                return e.HResult;
            }
        }

        public static int CreateComObject<T1, T2, T3, T4, T5, T6, T7, T8, IOut>(
            Func<T1, T2, T3, T4, T5, T6, T7, T8, IOut> callback,
            in T1 arg1,
            in T2 arg2,
            in T3 arg3,
            in T4 arg4,
            in T5 arg5,
            in T6 arg6,
            in T7 arg7,
            in T8 arg8,
            out IOut obj
            ) where IOut : class, IUnknown
        {
            try
            {
                obj = callback.Invoke(arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
                return 0;
            }
            catch (Exception e)
            {
#if DEBUG
                DirectX.PrintDebugMessage(e.Message);
                DirectX.PrintDebugMessage(e.StackTrace);
#endif

                obj = null;
                return e.HResult;
            }
        }

        public static int CreateComObject(
            Delegate callback,
            out IUnknown obj,
            params object[] args
            )
        {
            try
            {
                obj = callback.DynamicInvoke(args) as IUnknown;
                return 0;
            }
            catch (Exception e)
            {
#if DEBUG
                DirectX.PrintDebugMessage(e.Message);
                DirectX.PrintDebugMessage(e.StackTrace);
#endif

                obj = null;
                return e.HResult;
            }
        }
    }
}
