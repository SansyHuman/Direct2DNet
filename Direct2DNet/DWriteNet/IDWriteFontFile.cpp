#include "IDWriteFontFile.h"
#include "IDWriteFactory.h"

namespace D2DNet
{
    namespace DWriteNet
    {
        IDWriteFontFile::IDWriteFontFile(
            DWriteNet::IDWriteFactory ^factory,
            System::String ^filePath,
            System::Nullable<InteropServices::ComTypes::FILETIME> lastWriteTime)
        {
            marshal_context context;

            pin_ptr<::IDWriteFontFile *> ppFile = &m_pFile;

            HRESULT hr = factory->m_pFactory->CreateFontFileReference(
                context.marshal_as<const WCHAR *>(filePath),
                lastWriteTime.HasValue ? reinterpret_cast<::FILETIME *>(&lastWriteTime.Value) : __nullptr,
                (::IDWriteFontFile **)ppFile
            );

            ppFile = nullptr;

            if(FAILED(hr))
                throw gcnew Direct2DNet::Exception::DxException("Failed to create IDWriteFontFile.", (int)hr);
        }

        IDWriteFontFile::~IDWriteFontFile()
        {
            this->!IDWriteFontFile();
        }

        IDWriteFontFile::!IDWriteFontFile()
        {
            if(m_pFile)
            {
                m_pFile->Release();
                m_pFile = nullptr;
            }
        }

        void IDWriteFontFile::HandleCOMInterface(void *obj)
        {
            if(m_pFile)
            {
                m_pFile->Release();
            }

            m_pFile = (::IDWriteFontFile *)obj;
            m_pFile->AddRef();
        }

        HRESULT IDWriteFontFile::GetReferenceKey(
            void *%fontFileReferenceKey,
            UINT32 %fontFileReferenceKeySize)
        {
            const void *nativeKey;
            pin_ptr<UINT32> pSize = &fontFileReferenceKeySize;

            HRESULT hr = m_pFile->GetReferenceKey(
                &nativeKey, (UINT32 *)pSize
            );

            pSize = nullptr;

            fontFileReferenceKey = const_cast<void *>(nativeKey);
            return hr;
        }

        HRESULT IDWriteFontFile::Analyze(
            bool %isSupportedFontType,
            DWriteNet::DWRITE_FONT_FILE_TYPE %fontFileType,
            DWriteNet::DWRITE_FONT_FACE_TYPE %fontFaceType,
            UINT32 %numberOfFaces)
        {
            BOOL supported;
            ::DWRITE_FONT_FILE_TYPE fileType;
            ::DWRITE_FONT_FACE_TYPE faceType;
            UINT32 num;

            HRESULT hr = m_pFile->Analyze(&supported, &fileType, &faceType, &num);

            isSupportedFontType = System::Convert::ToBoolean(supported);
            fontFileType = (DWriteNet::DWRITE_FONT_FILE_TYPE)((int)fileType);
            fontFaceType = (DWriteNet::DWRITE_FONT_FACE_TYPE)((int)faceType);
            numberOfFaces = num;

            return hr;
        }

    }
}