#include "IStream.h"

namespace D2DNet
{
    namespace ComIO
    {
        IStream::IStream(System::String ^filename, ComIO::BSOS_OPTIONS options)
        {
            HRESULT hr = S_OK;

            marshal_context context;

            pin_ptr<::IRandomAccessStream *> ppRandomStream = &m_pRandomStream;
            hr = CreateRandomAccessStreamOnFile(
                context.marshal_as<PCWSTR>(filename),
                (DWORD)options,
                __uuidof(::IRandomAccessStream), (void **)ppRandomStream
            );
            ppRandomStream = nullptr;

            if(FAILED(hr))
                InteropServices::Marshal::ThrowExceptionForHR(hr);

            pin_ptr<::IStream *> ppStream = &m_pStream;
            hr = CreateStreamOverRandomAccessStream(m_pRandomStream, __uuidof(::IStream), (void **)ppStream);
            ppStream = nullptr;

            if(FAILED(hr))
            {
                if(m_pRandomStream)
                {
                    m_pRandomStream->Release();
                    m_pRandomStream = nullptr;
                }

                InteropServices::Marshal::ThrowExceptionForHR(hr);
            }
        }

        IStream::~IStream()
        {
            this->!IStream();
        }

        IStream::!IStream()
        {
            if(m_pRandomStream)
            {
                m_pRandomStream->Release();
                m_pRandomStream = nullptr;
            }

            if(m_pStream)
            {
                m_pStream->Release();
                m_pStream = nullptr;
            }
        }

        HRESULT IStream::Read(array<BYTE> ^pv, ULONG cb, ULONG %cbRead)
        {
            pin_ptr<BYTE> nativepv = &pv[0];
            pin_ptr<ULONG> pCbRead = &cbRead;

            return m_pStream->Read((void *)nativepv, cb, (ULONG *)pCbRead);
        }

        HRESULT IStream::Write(array<BYTE> ^pv, ULONG cb, ULONG %cbWritten)
        {
            pin_ptr<BYTE> nativepv = &pv[0];
            pin_ptr<ULONG> pCbWritten = &cbWritten;

            return m_pStream->Write((void *)nativepv, cb, (ULONG *)pCbWritten);
        }

        HRESULT IStream::Seek(D2DNet::LARGE_INTEGER %dlibMove, DWORD dwOrigin, D2DNet::ULARGE_INTEGER %libNewPosition)
        {
            pin_ptr<D2DNet::ULARGE_INTEGER> pLibNewPosition = &libNewPosition;

            return m_pStream->Seek(
                static_cast<::LARGE_INTEGER>(dlibMove),
                dwOrigin,
                (::ULARGE_INTEGER *)pLibNewPosition
            );
        }

        HRESULT IStream::SetSize(D2DNet::ULARGE_INTEGER %libNewSize)
        {
            return m_pStream->SetSize(static_cast<::ULARGE_INTEGER>(libNewSize));
        }

        HRESULT IStream::CopyTo(ComIO::IStream ^stm, D2DNet::ULARGE_INTEGER %cb, D2DNet::ULARGE_INTEGER %cbRead, D2DNet::ULARGE_INTEGER %cbWritten)
        {
            pin_ptr<D2DNet::ULARGE_INTEGER> pCbRead = &cbRead;
            pin_ptr<D2DNet::ULARGE_INTEGER> pCbWritten = &cbWritten;

            return m_pStream->CopyTo(
                stm->m_pStream,
                static_cast<::ULARGE_INTEGER>(cb),
                (::ULARGE_INTEGER *)pCbRead,
                (::ULARGE_INTEGER *)pCbWritten
            );
        }

        HRESULT IStream::Commit(ComIO::STGC grfCommitFlags)
        {
            return m_pStream->Commit((DWORD)grfCommitFlags);
        }

        HRESULT IStream::Revert()
        {
            return m_pStream->Revert();
        }

        HRESULT IStream::LockRegion(D2DNet::ULARGE_INTEGER %libOffset, D2DNet::ULARGE_INTEGER %cb, ComIO::LOCKTYPE lockType)
        {
            return m_pStream->LockRegion(
                static_cast<::ULARGE_INTEGER>(libOffset),
                static_cast<::ULARGE_INTEGER>(cb),
                (DWORD)lockType
            );
        }

        HRESULT IStream::UnlockRegion(D2DNet::ULARGE_INTEGER %libOffset, D2DNet::ULARGE_INTEGER %cb, ComIO::LOCKTYPE lockType)
        {
            return m_pStream->UnlockRegion(
                static_cast<::ULARGE_INTEGER>(libOffset),
                static_cast<::ULARGE_INTEGER>(cb),
                (DWORD)lockType
            );
        }

        HRESULT IStream::Stat(InteropServices::ComTypes::STATSTG %statstg, ComIO::STATFLAG grfStatFlag)
        {
            ::STATSTG stat = { 0 };
            HRESULT hr = m_pStream->Stat(&stat, (DWORD)grfStatFlag);

            if(FAILED(hr))
                return hr;

            statstg.pwcsName = marshal_as<System::String ^>(stat.pwcsName);
            statstg.type = stat.type;
            statstg.cbSize = stat.cbSize.QuadPart;
            statstg.mtime = *((InteropServices::ComTypes::FILETIME *)(&stat.mtime));
            statstg.ctime = *((InteropServices::ComTypes::FILETIME *)(&stat.ctime));
            statstg.atime = *((InteropServices::ComTypes::FILETIME *)(&stat.atime));
            statstg.grfMode = stat.grfMode;
            statstg.grfLocksSupported = stat.grfLocksSupported;
            statstg.clsid = DirectX::ToManagedGUID(stat.clsid);
            statstg.grfStateBits = stat.grfStateBits;
            statstg.reserved = stat.reserved;

            return hr;
        }

        HRESULT IStream::Clone(ComIO::IStream ^%stm)
        {
            ComIO::IStream ^clone = gcnew ComIO::IStream();

            pin_ptr<::IStream *> ppCloneStream = &clone->m_pStream;
            HRESULT hr = m_pStream->Clone((::IStream **)ppCloneStream);

            if(FAILED(hr)) {
                delete clone;
                stm = nullptr;
                return hr;
            }

            stm = clone;
            return hr;
        }

    }
}