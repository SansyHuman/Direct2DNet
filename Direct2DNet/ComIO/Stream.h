#pragma once

#include "ComIOHeaders.h"
#include "ComIOSettings.h"
#include "../DXCommonSettings.h"
#include "../IUnknown.h"

#include <msclr/marshal.h>

using namespace System::Runtime;
using namespace System::Runtime::CompilerServices;
using namespace ABI::Windows::Storage::Streams;
using namespace msclr::interop;

namespace D2DNet
{
    namespace ComIO
    {
        public ref class Stream : D2DNet::IUnknown
        {
        internal:
            ::IStream *m_pStream;
            ::IRandomAccessStream *m_pRandomStream;

        private:
            Stream() : m_pStream(nullptr), m_pRandomStream(nullptr) {}

        public:
            Stream(System::String ^filename, ComIO::BSOS_OPTIONS options);
            ~Stream();
            !Stream();

            property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pStream;
                }
            }

            virtual void HandleCOMInterface(void *obj)
            {
                if(m_pRandomStream)
                {
                    m_pRandomStream->Release();
                    m_pRandomStream = nullptr;
                }
                if(m_pStream)
                {
                    m_pStream->Release();
                }

                m_pStream = (::IStream *)obj;
                m_pStream->AddRef();
            }

            HRESULT Read(
                array<BYTE> ^pv,
                ULONG cb,
                [InteropServices::OutAttribute] ULONG %cbRead
            );

            HRESULT Write(
                array<BYTE> ^pv,
                ULONG cb,
                [InteropServices::OutAttribute] ULONG %cbWritten
            );

            HRESULT Seek(
                [InteropServices::InAttribute][IsReadOnlyAttribute] D2DNet::LARGE_INTEGER %dlibMove,
                DWORD dwOrigin,
                [InteropServices::OutAttribute] D2DNet::ULARGE_INTEGER %libNewPosition
            );

            HRESULT SetSize(
                [InteropServices::InAttribute][IsReadOnlyAttribute] D2DNet::ULARGE_INTEGER %libNewSize
            );

            HRESULT CopyTo(
                ComIO::Stream ^stm,
                [InteropServices::InAttribute][IsReadOnlyAttribute] D2DNet::ULARGE_INTEGER %cb,
                [InteropServices::OutAttribute] D2DNet::ULARGE_INTEGER %cbRead,
                [InteropServices::OutAttribute] D2DNet::ULARGE_INTEGER %cbWritten
            );

            HRESULT Commit(ComIO::STGC grfCommitFlags);

            HRESULT Revert();

            HRESULT LockRegion(
                [InteropServices::InAttribute][IsReadOnlyAttribute] D2DNet::ULARGE_INTEGER %libOffset,
                [InteropServices::InAttribute][IsReadOnlyAttribute] D2DNet::ULARGE_INTEGER %cb,
                ComIO::LOCKTYPE lockType
            );

            HRESULT UnlockRegion(
                [InteropServices::InAttribute][IsReadOnlyAttribute] D2DNet::ULARGE_INTEGER %libOffset,
                [InteropServices::InAttribute][IsReadOnlyAttribute] D2DNet::ULARGE_INTEGER %cb,
                ComIO::LOCKTYPE lockType
            );

            HRESULT Stat(
                [InteropServices::OutAttribute] InteropServices::ComTypes::STATSTG %statstg,
                ComIO::STATFLAG grfStatFlag
            );

            HRESULT Clone(
                [InteropServices::OutAttribute] ComIO::Stream ^%stm
            );
        };
    }
}