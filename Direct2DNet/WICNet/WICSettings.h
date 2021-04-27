#pragma once

#include "WICNetHeaders.h"
#include "../DXCommonSettings.h"

using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace D2DNet
{
    namespace WICNet
    {

#ifndef VENDOR_GUID
#define VENDOR_GUID static initonly System::Guid
#endif

#ifndef GET_VENDOR_GUID
#define GET_VENDOR_GUID(name) name ## = DirectX::ToManagedGUID(::GUID_Vendor ## name)
#endif

#ifndef RETURN_VENDOR_NAME
#define RETURN_VENDOR_NAME(name) if(vendorGuid == VendorGUID:: ## name) return #name
#endif

        /// <summary>
        /// The list of GUIDs of vendors.
        /// Vendors can identify components within their family through the vendor GUID. This is useful
        /// in arbitration of third-party components.
        /// </summary>
        public ref class VendorGUID abstract sealed
        {
        public:
            /// <summary>
            /// Prefer to use Microsoft encoder.
            /// </summary>
            VENDOR_GUID Microsoft;

            /// <summary>
            /// Prefer to use the native Microsoft encoder.
            /// </summary>
            VENDOR_GUID MicrosoftBuiltIn;

            static VendorGUID()
            {
                GET_VENDOR_GUID(Microsoft);
                GET_VENDOR_GUID(MicrosoftBuiltIn);
            }

            /// <summary>
            /// Gets the name of the vendor of the corresponding GUID.
            /// </summary>
            /// <param name="vendorGuid">
            /// The GUID of the vendor.
            /// </param>
            /// <returns>
            /// The name of the vendor, or "Unknown" if the GUID is not built-in.
            /// </returns>
            static System::String ^GetVendorName(
                [InAttribute][IsReadOnlyAttribute] System::Guid %vendorGuid
            )
            {
                RETURN_VENDOR_NAME(Microsoft);
                RETURN_VENDOR_NAME(MicrosoftBuiltIn);

                return "Unknown";
            }
        };

#ifndef CONTAINER_GUID
#define CONTAINER_GUID static initonly System::Guid
#endif

#ifndef GET_CONTAINER_GUID
#define GET_CONTAINER_GUID(name) name ## = DirectX::ToManagedGUID(::GUID_ContainerFormat ## name)
#endif

#ifndef RETURN_FORMAT_NAME
#define RETURN_FORMAT_NAME(name) if(formatGuid == ContainerFormatGUID:: ## name) return #name
#endif

        /// <summary>
        /// The list of GUIDs of built-in containder formats.
        /// </summary>
        public ref class ContainerFormatGUID abstract sealed
        {
        public:
            CONTAINER_GUID Bmp;
            CONTAINER_GUID Png;
            CONTAINER_GUID Ico;
            CONTAINER_GUID Jpeg;
            CONTAINER_GUID Tiff;
            CONTAINER_GUID Gif;
            CONTAINER_GUID Wmp;
            CONTAINER_GUID Dds;
            CONTAINER_GUID Adng;
            CONTAINER_GUID Heif;
            CONTAINER_GUID Webp;
            CONTAINER_GUID Raw;

            static ContainerFormatGUID()
            {
                GET_CONTAINER_GUID(Bmp);
                GET_CONTAINER_GUID(Png);
                GET_CONTAINER_GUID(Ico);
                GET_CONTAINER_GUID(Jpeg);
                GET_CONTAINER_GUID(Tiff);
                GET_CONTAINER_GUID(Gif);
                GET_CONTAINER_GUID(Wmp);
                GET_CONTAINER_GUID(Dds);
                GET_CONTAINER_GUID(Adng);
                GET_CONTAINER_GUID(Heif);
                GET_CONTAINER_GUID(Webp);
                GET_CONTAINER_GUID(Raw);
            }

            /// <summary>
            /// Gets the name of the format of the corresponding GUID.
            /// </summary>
            /// <param name="formatGuid">
            /// The GUID of the format.
            /// </param>
            /// <returns>
            /// The name of the format, or "Unknown" if the GUID is not built-in.
            /// </returns>
            static System::String ^GetFormatName(
                [InAttribute][IsReadOnlyAttribute] System::Guid %formatGuid
            )
            {
                RETURN_FORMAT_NAME(Bmp);
                RETURN_FORMAT_NAME(Png);
                RETURN_FORMAT_NAME(Ico);
                RETURN_FORMAT_NAME(Jpeg);
                RETURN_FORMAT_NAME(Tiff);
                RETURN_FORMAT_NAME(Gif);
                RETURN_FORMAT_NAME(Wmp);
                RETURN_FORMAT_NAME(Dds);
                RETURN_FORMAT_NAME(Adng);
                RETURN_FORMAT_NAME(Heif);
                RETURN_FORMAT_NAME(Webp);
                RETURN_FORMAT_NAME(Raw);

                return "Unknown";
            }
        };

#ifndef PIXEL_FORMAT_GUID
#define PIXEL_FORMAT_GUID static initonly System::Guid
#endif

#ifndef GET_PIXEL_FORMAT_GUID
#define GET_PIXEL_FORMAT_GUID(name) name ## = DirectX::ToManagedGUID(::GUID_WICPixel ## name)
#endif

#ifndef RETURN_PIXEL_FORMAT_NAME
#define RETURN_PIXEL_FORMAT_NAME(name) if(formatGuid == PixelFormatGUID:: ## name) return #name
#endif

        /// <summary>
        /// The list of GUIDs of built-in pixel formats.
        /// </summary>
        public ref class PixelFormatGUID abstract sealed
        {
        public:
            PIXEL_FORMAT_GUID FormatDontCare                       ;
            PIXEL_FORMAT_GUID Format1bppIndexed                    ;
            PIXEL_FORMAT_GUID Format2bppIndexed                    ;
            PIXEL_FORMAT_GUID Format4bppIndexed                    ;
            PIXEL_FORMAT_GUID Format8bppIndexed                    ;
            PIXEL_FORMAT_GUID FormatBlackWhite                     ;
            PIXEL_FORMAT_GUID Format2bppGray                       ;
            PIXEL_FORMAT_GUID Format4bppGray                       ;
            PIXEL_FORMAT_GUID Format8bppGray                       ;
            PIXEL_FORMAT_GUID Format8bppAlpha                      ;
            PIXEL_FORMAT_GUID Format16bppBGR555                    ;
            PIXEL_FORMAT_GUID Format16bppBGR565                    ;
            PIXEL_FORMAT_GUID Format16bppBGRA5551                  ;
            PIXEL_FORMAT_GUID Format16bppGray                      ;
            PIXEL_FORMAT_GUID Format24bppBGR                       ;
            PIXEL_FORMAT_GUID Format24bppRGB                       ;
            PIXEL_FORMAT_GUID Format32bppBGR                       ;
            PIXEL_FORMAT_GUID Format32bppBGRA                      ;
            PIXEL_FORMAT_GUID Format32bppPBGRA                     ;
            PIXEL_FORMAT_GUID Format32bppGrayFloat                 ;
            PIXEL_FORMAT_GUID Format32bppRGB                       ;
            PIXEL_FORMAT_GUID Format32bppRGBA                      ;
            PIXEL_FORMAT_GUID Format32bppPRGBA                     ;
            PIXEL_FORMAT_GUID Format48bppRGB                       ;
            PIXEL_FORMAT_GUID Format48bppBGR                       ;
            PIXEL_FORMAT_GUID Format64bppRGB                       ;
            PIXEL_FORMAT_GUID Format64bppRGBA                      ;
            PIXEL_FORMAT_GUID Format64bppBGRA                      ;
            PIXEL_FORMAT_GUID Format64bppPRGBA                     ;
            PIXEL_FORMAT_GUID Format64bppPBGRA                     ;
            PIXEL_FORMAT_GUID Format16bppGrayFixedPoint            ;
            PIXEL_FORMAT_GUID Format32bppBGR101010                 ;
            PIXEL_FORMAT_GUID Format48bppRGBFixedPoint             ;
            PIXEL_FORMAT_GUID Format48bppBGRFixedPoint             ;
            PIXEL_FORMAT_GUID Format96bppRGBFixedPoint             ;
            PIXEL_FORMAT_GUID Format96bppRGBFloat                  ;
            PIXEL_FORMAT_GUID Format128bppRGBAFloat                ;
            PIXEL_FORMAT_GUID Format128bppPRGBAFloat               ;
            PIXEL_FORMAT_GUID Format128bppRGBFloat                 ;
            PIXEL_FORMAT_GUID Format32bppCMYK                      ;
            PIXEL_FORMAT_GUID Format64bppRGBAFixedPoint            ;
            PIXEL_FORMAT_GUID Format64bppBGRAFixedPoint            ;
            PIXEL_FORMAT_GUID Format64bppRGBFixedPoint             ;
            PIXEL_FORMAT_GUID Format128bppRGBAFixedPoint           ;
            PIXEL_FORMAT_GUID Format128bppRGBFixedPoint            ;
            PIXEL_FORMAT_GUID Format64bppRGBAHalf                  ;
            PIXEL_FORMAT_GUID Format64bppPRGBAHalf                 ;
            PIXEL_FORMAT_GUID Format64bppRGBHalf                   ;
            PIXEL_FORMAT_GUID Format48bppRGBHalf                   ;
            PIXEL_FORMAT_GUID Format32bppRGBE                      ;
            PIXEL_FORMAT_GUID Format16bppGrayHalf                  ;
            PIXEL_FORMAT_GUID Format32bppGrayFixedPoint            ;
            PIXEL_FORMAT_GUID Format32bppRGBA1010102               ;
            PIXEL_FORMAT_GUID Format32bppRGBA1010102XR             ;
            PIXEL_FORMAT_GUID Format32bppR10G10B10A2               ;
            PIXEL_FORMAT_GUID Format32bppR10G10B10A2HDR10          ;
            PIXEL_FORMAT_GUID Format64bppCMYK                      ;
            PIXEL_FORMAT_GUID Format24bpp3Channels                 ;
            PIXEL_FORMAT_GUID Format32bpp4Channels                 ;
            PIXEL_FORMAT_GUID Format40bpp5Channels                 ;
            PIXEL_FORMAT_GUID Format48bpp6Channels                 ;
            PIXEL_FORMAT_GUID Format56bpp7Channels                 ;
            PIXEL_FORMAT_GUID Format64bpp8Channels                 ;
            PIXEL_FORMAT_GUID Format48bpp3Channels                 ;
            PIXEL_FORMAT_GUID Format64bpp4Channels                 ;
            PIXEL_FORMAT_GUID Format80bpp5Channels                 ;
            PIXEL_FORMAT_GUID Format96bpp6Channels                 ;
            PIXEL_FORMAT_GUID Format112bpp7Channels                ;
            PIXEL_FORMAT_GUID Format128bpp8Channels                ;
            PIXEL_FORMAT_GUID Format40bppCMYKAlpha                 ;
            PIXEL_FORMAT_GUID Format80bppCMYKAlpha                 ;
            PIXEL_FORMAT_GUID Format32bpp3ChannelsAlpha            ;
            PIXEL_FORMAT_GUID Format40bpp4ChannelsAlpha            ;
            PIXEL_FORMAT_GUID Format48bpp5ChannelsAlpha            ;
            PIXEL_FORMAT_GUID Format56bpp6ChannelsAlpha            ;
            PIXEL_FORMAT_GUID Format64bpp7ChannelsAlpha            ;
            PIXEL_FORMAT_GUID Format72bpp8ChannelsAlpha            ;
            PIXEL_FORMAT_GUID Format64bpp3ChannelsAlpha            ;
            PIXEL_FORMAT_GUID Format80bpp4ChannelsAlpha            ;
            PIXEL_FORMAT_GUID Format96bpp5ChannelsAlpha            ;
            PIXEL_FORMAT_GUID Format112bpp6ChannelsAlpha           ;
            PIXEL_FORMAT_GUID Format128bpp7ChannelsAlpha           ;
            PIXEL_FORMAT_GUID Format144bpp8ChannelsAlpha           ;
            PIXEL_FORMAT_GUID Format8bppY                          ;
            PIXEL_FORMAT_GUID Format8bppCb                         ;
            PIXEL_FORMAT_GUID Format8bppCr                         ;
            PIXEL_FORMAT_GUID Format16bppCbCr                      ;
            PIXEL_FORMAT_GUID Format16bppYQuantizedDctCoefficients ;
            PIXEL_FORMAT_GUID Format16bppCbQuantizedDctCoefficients;
            PIXEL_FORMAT_GUID Format16bppCrQuantizedDctCoefficients;

            static PixelFormatGUID()
            {
                GET_PIXEL_FORMAT_GUID(FormatDontCare                       );
                GET_PIXEL_FORMAT_GUID(Format1bppIndexed                    );
                GET_PIXEL_FORMAT_GUID(Format2bppIndexed                    );
                GET_PIXEL_FORMAT_GUID(Format4bppIndexed                    );
                GET_PIXEL_FORMAT_GUID(Format8bppIndexed                    );
                GET_PIXEL_FORMAT_GUID(FormatBlackWhite                     );
                GET_PIXEL_FORMAT_GUID(Format2bppGray                       );
                GET_PIXEL_FORMAT_GUID(Format4bppGray                       );
                GET_PIXEL_FORMAT_GUID(Format8bppGray                       );
                GET_PIXEL_FORMAT_GUID(Format8bppAlpha                      );
                GET_PIXEL_FORMAT_GUID(Format16bppBGR555                    );
                GET_PIXEL_FORMAT_GUID(Format16bppBGR565                    );
                GET_PIXEL_FORMAT_GUID(Format16bppBGRA5551                  );
                GET_PIXEL_FORMAT_GUID(Format16bppGray                      );
                GET_PIXEL_FORMAT_GUID(Format24bppBGR                       );
                GET_PIXEL_FORMAT_GUID(Format24bppRGB                       );
                GET_PIXEL_FORMAT_GUID(Format32bppBGR                       );
                GET_PIXEL_FORMAT_GUID(Format32bppBGRA                      );
                GET_PIXEL_FORMAT_GUID(Format32bppPBGRA                     );
                GET_PIXEL_FORMAT_GUID(Format32bppGrayFloat                 );
                GET_PIXEL_FORMAT_GUID(Format32bppRGB                       );
                GET_PIXEL_FORMAT_GUID(Format32bppRGBA                      );
                GET_PIXEL_FORMAT_GUID(Format32bppPRGBA                     );
                GET_PIXEL_FORMAT_GUID(Format48bppRGB                       );
                GET_PIXEL_FORMAT_GUID(Format48bppBGR                       );
                GET_PIXEL_FORMAT_GUID(Format64bppRGB                       );
                GET_PIXEL_FORMAT_GUID(Format64bppRGBA                      );
                GET_PIXEL_FORMAT_GUID(Format64bppBGRA                      );
                GET_PIXEL_FORMAT_GUID(Format64bppPRGBA                     );
                GET_PIXEL_FORMAT_GUID(Format64bppPBGRA                     );
                GET_PIXEL_FORMAT_GUID(Format16bppGrayFixedPoint            );
                GET_PIXEL_FORMAT_GUID(Format32bppBGR101010                 );
                GET_PIXEL_FORMAT_GUID(Format48bppRGBFixedPoint             );
                GET_PIXEL_FORMAT_GUID(Format48bppBGRFixedPoint             );
                GET_PIXEL_FORMAT_GUID(Format96bppRGBFixedPoint             );
                GET_PIXEL_FORMAT_GUID(Format96bppRGBFloat                  );
                GET_PIXEL_FORMAT_GUID(Format128bppRGBAFloat                );
                GET_PIXEL_FORMAT_GUID(Format128bppPRGBAFloat               );
                GET_PIXEL_FORMAT_GUID(Format128bppRGBFloat                 );
                GET_PIXEL_FORMAT_GUID(Format32bppCMYK                      );
                GET_PIXEL_FORMAT_GUID(Format64bppRGBAFixedPoint            );
                GET_PIXEL_FORMAT_GUID(Format64bppBGRAFixedPoint            );
                GET_PIXEL_FORMAT_GUID(Format64bppRGBFixedPoint             );
                GET_PIXEL_FORMAT_GUID(Format128bppRGBAFixedPoint           );
                GET_PIXEL_FORMAT_GUID(Format128bppRGBFixedPoint            );
                GET_PIXEL_FORMAT_GUID(Format64bppRGBAHalf                  );
                GET_PIXEL_FORMAT_GUID(Format64bppPRGBAHalf                 );
                GET_PIXEL_FORMAT_GUID(Format64bppRGBHalf                   );
                GET_PIXEL_FORMAT_GUID(Format48bppRGBHalf                   );
                GET_PIXEL_FORMAT_GUID(Format32bppRGBE                      );
                GET_PIXEL_FORMAT_GUID(Format16bppGrayHalf                  );
                GET_PIXEL_FORMAT_GUID(Format32bppGrayFixedPoint            );
                GET_PIXEL_FORMAT_GUID(Format32bppRGBA1010102               );
                GET_PIXEL_FORMAT_GUID(Format32bppRGBA1010102XR             );
                GET_PIXEL_FORMAT_GUID(Format32bppR10G10B10A2               );
                GET_PIXEL_FORMAT_GUID(Format32bppR10G10B10A2HDR10          );
                GET_PIXEL_FORMAT_GUID(Format64bppCMYK                      );
                GET_PIXEL_FORMAT_GUID(Format24bpp3Channels                 );
                GET_PIXEL_FORMAT_GUID(Format32bpp4Channels                 );
                GET_PIXEL_FORMAT_GUID(Format40bpp5Channels                 );
                GET_PIXEL_FORMAT_GUID(Format48bpp6Channels                 );
                GET_PIXEL_FORMAT_GUID(Format56bpp7Channels                 );
                GET_PIXEL_FORMAT_GUID(Format64bpp8Channels                 );
                GET_PIXEL_FORMAT_GUID(Format48bpp3Channels                 );
                GET_PIXEL_FORMAT_GUID(Format64bpp4Channels                 );
                GET_PIXEL_FORMAT_GUID(Format80bpp5Channels                 );
                GET_PIXEL_FORMAT_GUID(Format96bpp6Channels                 );
                GET_PIXEL_FORMAT_GUID(Format112bpp7Channels                );
                GET_PIXEL_FORMAT_GUID(Format128bpp8Channels                );
                GET_PIXEL_FORMAT_GUID(Format40bppCMYKAlpha                 );
                GET_PIXEL_FORMAT_GUID(Format80bppCMYKAlpha                 );
                GET_PIXEL_FORMAT_GUID(Format32bpp3ChannelsAlpha            );
                GET_PIXEL_FORMAT_GUID(Format40bpp4ChannelsAlpha            );
                GET_PIXEL_FORMAT_GUID(Format48bpp5ChannelsAlpha            );
                GET_PIXEL_FORMAT_GUID(Format56bpp6ChannelsAlpha            );
                GET_PIXEL_FORMAT_GUID(Format64bpp7ChannelsAlpha            );
                GET_PIXEL_FORMAT_GUID(Format72bpp8ChannelsAlpha            );
                GET_PIXEL_FORMAT_GUID(Format64bpp3ChannelsAlpha            );
                GET_PIXEL_FORMAT_GUID(Format80bpp4ChannelsAlpha            );
                GET_PIXEL_FORMAT_GUID(Format96bpp5ChannelsAlpha            );
                GET_PIXEL_FORMAT_GUID(Format112bpp6ChannelsAlpha           );
                GET_PIXEL_FORMAT_GUID(Format128bpp7ChannelsAlpha           );
                GET_PIXEL_FORMAT_GUID(Format144bpp8ChannelsAlpha           );
                GET_PIXEL_FORMAT_GUID(Format8bppY                          );
                GET_PIXEL_FORMAT_GUID(Format8bppCb                         );
                GET_PIXEL_FORMAT_GUID(Format8bppCr                         );
                GET_PIXEL_FORMAT_GUID(Format16bppCbCr                      );
                GET_PIXEL_FORMAT_GUID(Format16bppYQuantizedDctCoefficients );
                GET_PIXEL_FORMAT_GUID(Format16bppCbQuantizedDctCoefficients);
                GET_PIXEL_FORMAT_GUID(Format16bppCrQuantizedDctCoefficients);
            }

            /// <summary>
            /// Gets the name of the pixel format of the corresponding GUID.
            /// </summary>
            /// <param name="formatGuid">
            /// The GUID of the pixel format.
            /// </param>
            /// <returns>
            /// The name of the pixel format, or "Unknown" if the GUID is not built-in.
            /// </returns>
            static System::String ^GetFormatName(
                [InAttribute][IsReadOnlyAttribute] System::Guid %formatGuid
            )
            {
                RETURN_PIXEL_FORMAT_NAME(FormatDontCare                       );
                RETURN_PIXEL_FORMAT_NAME(Format1bppIndexed                    );
                RETURN_PIXEL_FORMAT_NAME(Format2bppIndexed                    );
                RETURN_PIXEL_FORMAT_NAME(Format4bppIndexed                    );
                RETURN_PIXEL_FORMAT_NAME(Format8bppIndexed                    );
                RETURN_PIXEL_FORMAT_NAME(FormatBlackWhite                     );
                RETURN_PIXEL_FORMAT_NAME(Format2bppGray                       );
                RETURN_PIXEL_FORMAT_NAME(Format4bppGray                       );
                RETURN_PIXEL_FORMAT_NAME(Format8bppGray                       );
                RETURN_PIXEL_FORMAT_NAME(Format8bppAlpha                      );
                RETURN_PIXEL_FORMAT_NAME(Format16bppBGR555                    );
                RETURN_PIXEL_FORMAT_NAME(Format16bppBGR565                    );
                RETURN_PIXEL_FORMAT_NAME(Format16bppBGRA5551                  );
                RETURN_PIXEL_FORMAT_NAME(Format16bppGray                      );
                RETURN_PIXEL_FORMAT_NAME(Format24bppBGR                       );
                RETURN_PIXEL_FORMAT_NAME(Format24bppRGB                       );
                RETURN_PIXEL_FORMAT_NAME(Format32bppBGR                       );
                RETURN_PIXEL_FORMAT_NAME(Format32bppBGRA                      );
                RETURN_PIXEL_FORMAT_NAME(Format32bppPBGRA                     );
                RETURN_PIXEL_FORMAT_NAME(Format32bppGrayFloat                 );
                RETURN_PIXEL_FORMAT_NAME(Format32bppRGB                       );
                RETURN_PIXEL_FORMAT_NAME(Format32bppRGBA                      );
                RETURN_PIXEL_FORMAT_NAME(Format32bppPRGBA                     );
                RETURN_PIXEL_FORMAT_NAME(Format48bppRGB                       );
                RETURN_PIXEL_FORMAT_NAME(Format48bppBGR                       );
                RETURN_PIXEL_FORMAT_NAME(Format64bppRGB                       );
                RETURN_PIXEL_FORMAT_NAME(Format64bppRGBA                      );
                RETURN_PIXEL_FORMAT_NAME(Format64bppBGRA                      );
                RETURN_PIXEL_FORMAT_NAME(Format64bppPRGBA                     );
                RETURN_PIXEL_FORMAT_NAME(Format64bppPBGRA                     );
                RETURN_PIXEL_FORMAT_NAME(Format16bppGrayFixedPoint            );
                RETURN_PIXEL_FORMAT_NAME(Format32bppBGR101010                 );
                RETURN_PIXEL_FORMAT_NAME(Format48bppRGBFixedPoint             );
                RETURN_PIXEL_FORMAT_NAME(Format48bppBGRFixedPoint             );
                RETURN_PIXEL_FORMAT_NAME(Format96bppRGBFixedPoint             );
                RETURN_PIXEL_FORMAT_NAME(Format96bppRGBFloat                  );
                RETURN_PIXEL_FORMAT_NAME(Format128bppRGBAFloat                );
                RETURN_PIXEL_FORMAT_NAME(Format128bppPRGBAFloat               );
                RETURN_PIXEL_FORMAT_NAME(Format128bppRGBFloat                 );
                RETURN_PIXEL_FORMAT_NAME(Format32bppCMYK                      );
                RETURN_PIXEL_FORMAT_NAME(Format64bppRGBAFixedPoint            );
                RETURN_PIXEL_FORMAT_NAME(Format64bppBGRAFixedPoint            );
                RETURN_PIXEL_FORMAT_NAME(Format64bppRGBFixedPoint             );
                RETURN_PIXEL_FORMAT_NAME(Format128bppRGBAFixedPoint           );
                RETURN_PIXEL_FORMAT_NAME(Format128bppRGBFixedPoint            );
                RETURN_PIXEL_FORMAT_NAME(Format64bppRGBAHalf                  );
                RETURN_PIXEL_FORMAT_NAME(Format64bppPRGBAHalf                 );
                RETURN_PIXEL_FORMAT_NAME(Format64bppRGBHalf                   );
                RETURN_PIXEL_FORMAT_NAME(Format48bppRGBHalf                   );
                RETURN_PIXEL_FORMAT_NAME(Format32bppRGBE                      );
                RETURN_PIXEL_FORMAT_NAME(Format16bppGrayHalf                  );
                RETURN_PIXEL_FORMAT_NAME(Format32bppGrayFixedPoint            );
                RETURN_PIXEL_FORMAT_NAME(Format32bppRGBA1010102               );
                RETURN_PIXEL_FORMAT_NAME(Format32bppRGBA1010102XR             );
                RETURN_PIXEL_FORMAT_NAME(Format32bppR10G10B10A2               );
                RETURN_PIXEL_FORMAT_NAME(Format32bppR10G10B10A2HDR10          );
                RETURN_PIXEL_FORMAT_NAME(Format64bppCMYK                      );
                RETURN_PIXEL_FORMAT_NAME(Format24bpp3Channels                 );
                RETURN_PIXEL_FORMAT_NAME(Format32bpp4Channels                 );
                RETURN_PIXEL_FORMAT_NAME(Format40bpp5Channels                 );
                RETURN_PIXEL_FORMAT_NAME(Format48bpp6Channels                 );
                RETURN_PIXEL_FORMAT_NAME(Format56bpp7Channels                 );
                RETURN_PIXEL_FORMAT_NAME(Format64bpp8Channels                 );
                RETURN_PIXEL_FORMAT_NAME(Format48bpp3Channels                 );
                RETURN_PIXEL_FORMAT_NAME(Format64bpp4Channels                 );
                RETURN_PIXEL_FORMAT_NAME(Format80bpp5Channels                 );
                RETURN_PIXEL_FORMAT_NAME(Format96bpp6Channels                 );
                RETURN_PIXEL_FORMAT_NAME(Format112bpp7Channels                );
                RETURN_PIXEL_FORMAT_NAME(Format128bpp8Channels                );
                RETURN_PIXEL_FORMAT_NAME(Format40bppCMYKAlpha                 );
                RETURN_PIXEL_FORMAT_NAME(Format80bppCMYKAlpha                 );
                RETURN_PIXEL_FORMAT_NAME(Format32bpp3ChannelsAlpha            );
                RETURN_PIXEL_FORMAT_NAME(Format40bpp4ChannelsAlpha            );
                RETURN_PIXEL_FORMAT_NAME(Format48bpp5ChannelsAlpha            );
                RETURN_PIXEL_FORMAT_NAME(Format56bpp6ChannelsAlpha            );
                RETURN_PIXEL_FORMAT_NAME(Format64bpp7ChannelsAlpha            );
                RETURN_PIXEL_FORMAT_NAME(Format72bpp8ChannelsAlpha            );
                RETURN_PIXEL_FORMAT_NAME(Format64bpp3ChannelsAlpha            );
                RETURN_PIXEL_FORMAT_NAME(Format80bpp4ChannelsAlpha            );
                RETURN_PIXEL_FORMAT_NAME(Format96bpp5ChannelsAlpha            );
                RETURN_PIXEL_FORMAT_NAME(Format112bpp6ChannelsAlpha           );
                RETURN_PIXEL_FORMAT_NAME(Format128bpp7ChannelsAlpha           );
                RETURN_PIXEL_FORMAT_NAME(Format144bpp8ChannelsAlpha           );
                RETURN_PIXEL_FORMAT_NAME(Format8bppY                          );
                RETURN_PIXEL_FORMAT_NAME(Format8bppCb                         );
                RETURN_PIXEL_FORMAT_NAME(Format8bppCr                         );
                RETURN_PIXEL_FORMAT_NAME(Format16bppCbCr                      );
                RETURN_PIXEL_FORMAT_NAME(Format16bppYQuantizedDctCoefficients );
                RETURN_PIXEL_FORMAT_NAME(Format16bppCbQuantizedDctCoefficients);
                RETURN_PIXEL_FORMAT_NAME(Format16bppCrQuantizedDctCoefficients);

                return "Unknown";
            }
        };

#ifndef CONST_CLSID
#define CONST_CLSID static initonly System::Guid
#endif

#ifndef GET_CLSID
#define GET_CLSID(name) name ## = DirectX::ToManagedGUID(::CLSID_ ## name)
#endif

#ifndef RETURN_CLSNAME
#define RETURN_CLSNAME(name) if(clsid == WICClassID:: ## name) return #name
#endif

        /// <summary>
        /// The list of built-in CLSIDs.
        /// </summary>
        public ref class WICClassID abstract sealed
        {
        public:
            CONST_CLSID WICImagingFactory          ;
            CONST_CLSID WICPngDecoder              ;
            CONST_CLSID WICBmpDecoder              ;
            CONST_CLSID WICIcoDecoder              ;
            CONST_CLSID WICJpegDecoder             ;
            CONST_CLSID WICGifDecoder              ;
            CONST_CLSID WICTiffDecoder             ;
            CONST_CLSID WICWmpDecoder              ;
            CONST_CLSID WICDdsDecoder              ;
            CONST_CLSID WICBmpEncoder              ;
            CONST_CLSID WICPngEncoder              ;
            CONST_CLSID WICJpegEncoder             ;
            CONST_CLSID WICGifEncoder              ;
            CONST_CLSID WICTiffEncoder             ;
            CONST_CLSID WICWmpEncoder              ;
            CONST_CLSID WICDdsEncoder              ;
            CONST_CLSID WICAdngDecoder             ;
            CONST_CLSID WICJpegQualcommPhoneEncoder;
            CONST_CLSID WICHeifDecoder             ;
            CONST_CLSID WICHeifEncoder             ;
            CONST_CLSID WICWebpDecoder             ;
            CONST_CLSID WICRAWDecoder              ;

            static WICClassID()
            {
                GET_CLSID(WICImagingFactory          );
                GET_CLSID(WICPngDecoder              );
                GET_CLSID(WICBmpDecoder              );
                GET_CLSID(WICIcoDecoder              );
                GET_CLSID(WICJpegDecoder             );
                GET_CLSID(WICGifDecoder              );
                GET_CLSID(WICTiffDecoder             );
                GET_CLSID(WICWmpDecoder              );
                GET_CLSID(WICDdsDecoder              );
                GET_CLSID(WICBmpEncoder              );
                GET_CLSID(WICPngEncoder              );
                GET_CLSID(WICJpegEncoder             );
                GET_CLSID(WICGifEncoder              );
                GET_CLSID(WICTiffEncoder             );
                GET_CLSID(WICWmpEncoder              );
                GET_CLSID(WICDdsEncoder              );
                GET_CLSID(WICAdngDecoder             );
                GET_CLSID(WICJpegQualcommPhoneEncoder);
                GET_CLSID(WICHeifDecoder             );
                GET_CLSID(WICHeifEncoder             );
                GET_CLSID(WICWebpDecoder             );
                GET_CLSID(WICRAWDecoder              );
            }

            /// <summary>
            /// Gets the name of the class of the corresponding GUID.
            /// </summary>
            /// <param name="clsid">
            /// The GUID of the class.
            /// </param>
            /// <returns>
            /// The name of the class, or "Unknown" if the GUID is not built-in.
            /// </returns>
            static System::String ^GetClassName(
                [InAttribute][IsReadOnlyAttribute] System::Guid %clsid
            )
            {
                RETURN_CLSNAME(WICImagingFactory          );
                RETURN_CLSNAME(WICPngDecoder              );
                RETURN_CLSNAME(WICBmpDecoder              );
                RETURN_CLSNAME(WICIcoDecoder              );
                RETURN_CLSNAME(WICJpegDecoder             );
                RETURN_CLSNAME(WICGifDecoder              );
                RETURN_CLSNAME(WICTiffDecoder             );
                RETURN_CLSNAME(WICWmpDecoder              );
                RETURN_CLSNAME(WICDdsDecoder              );
                RETURN_CLSNAME(WICBmpEncoder              );
                RETURN_CLSNAME(WICPngEncoder              );
                RETURN_CLSNAME(WICJpegEncoder             );
                RETURN_CLSNAME(WICGifEncoder              );
                RETURN_CLSNAME(WICTiffEncoder             );
                RETURN_CLSNAME(WICWmpEncoder              );
                RETURN_CLSNAME(WICDdsEncoder              );
                RETURN_CLSNAME(WICAdngDecoder             );
                RETURN_CLSNAME(WICJpegQualcommPhoneEncoder);
                RETURN_CLSNAME(WICHeifDecoder             );
                RETURN_CLSNAME(WICHeifEncoder             );
                RETURN_CLSNAME(WICWebpDecoder             );
                RETURN_CLSNAME(WICRAWDecoder              );

                return "Unknown";
            }
        };

        /// <summary>
        /// Enum of generic access rights
        /// </summary>
        [System::FlagsAttribute]
        public enum class Access : DWORD
        {
            NONE = 0,

            /// <summary>
            /// Read access.
            /// </summary>
            READ = GENERIC_READ,

            /// <summary>
            /// Write access.
            /// </summary>
            WRITE = GENERIC_WRITE
        };

        /// <summary>
        /// Specifies decode options.
        /// </summary>
        public enum class WICDecodeOptions : DWORD
        {
            /// <summary>
            /// Cache metadata when needed.
            /// </summary>
            MetadataCacheOnDemand = 0,

            /// <summary>
            /// Cache metadata when decoder is loaded.
            /// </summary>
            MetadataCacheOnLoad = 0x1
        };

        /// <summary>
        /// Specifies the capabilities of the decoder.
        /// </summary>
        [System::FlagsAttribute]
        public enum class WICBitmapDecoderCapabilities : DWORD
        {
            None = 0,

            /// <summary>
            /// Decoder recognizes the image was encoded with an encoder produced by the same vendor.
            /// </summary>
            SameEncoder = 0x1,

            /// <summary>
            /// Decoder can decode all the images within an image container.
            /// </summary>
            CanDecodeAllImages = 0x2,

            /// <summary>
            /// Decoder can decode some of the images within an image container.
            /// </summary>
            CanDecodeSomeImages = 0x4,

            /// <summary>
            /// Decoder can enumerate the metadata blocks within a container format.
            /// </summary>
            CanEnumerateMetadata = 0x8,

            /// <summary>
            /// Decoder can find and decode a thumbnail.
            /// </summary>
            CanDecodeThumbnail = 0x10,
        };

        /// <summary>
        /// Represents a rectangle for Windows Imaging Component (WIC) API.
        /// </summary>
        public value struct WICRect
        {
            /// <summary>
            /// The horizontal coordinate of the rectangle.
            /// </summary>
            INT x;

            /// <summary>
            /// The vertical coordinate of the rectangle.
            /// </summary>
            INT y;

            /// <summary>
            /// The width of the rectangle.
            /// </summary>
            INT width;

            /// <summary>
            /// The height of the rectangle.
            /// </summary>
            INT height;

            WICRect(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
        };

        /// <summary>
        /// Represents a rectangle for Windows Imaging Component (WIC) API.
        /// </summary>
        public enum class WICBitmapDitherType : DWORD
        {
            /// <summary>
            /// A solid color algorithm without dither.
            /// </summary>
            None = 0,

            /// <summary>
            /// A solid color algorithm without dither.
            /// </summary>
            Solid = 0,

            /// <summary>
            /// A 4x4 ordered dither algorithm.
            /// </summary>
            Ordered4x4 = 0x1,

            /// <summary>
            /// An 8x8 ordered dither algorithm.
            /// </summary>
            Ordered8x8 = 0x2,

            /// <summary>
            /// A 16x16 ordered dither algorithm.
            /// </summary>
            Ordered16x16 = 0x3,

            /// <summary>
            /// A 4x4 spiral dither algorithm.
            /// </summary>
            Spiral4x4 = 0x4,

            /// <summary>
            /// An 8x8 spiral dither algorithm.
            /// </summary>
            Spiral8x8 = 0x5,

            /// <summary>
            /// A 4x4 dual spiral dither algorithm.
            /// </summary>
            DualSpiral4x4 = 0x6,

            /// <summary>
            /// An 8x8 dual spiral dither algorithm.
            /// </summary>
            DualSpiral8x8 = 0x7,

            /// <summary>
            /// An error diffusion algorithm.
            /// </summary>
            ErrorDiffusion = 0x8,
        };

        /// <summary>
        /// Specifies the type of palette used for an indexed image format.
        /// </summary>
        public enum class WICBitmapPaletteType : DWORD
        {
            /// <summary>
            /// An arbitrary custom palette provided by caller.
            /// </summary>
            Custom = 0,

            /// <summary>
            /// An optimal palette generated using a median-cut algorithm. Derived from the colors in an image.
            /// </summary>
            MedianCut = 0x1,

            /// <summary>
            /// A black and white palette.
            /// </summary>
            FixedBW = 0x2,

            /// <summary>
            /// A palette that has its 8-color on-off primaries and the 16 system colors added. With
            /// duplicates removed, 16 colors are available.
            /// </summary>
            FixedHalftone8 = 0x3,

            /// <summary>
            /// A palette that has 3 intensity levels of each primary: 27-color on-off primaries and the
            /// 16 system colors added. With duplicates removed, 35 colors are available.
            /// </summary>
            FixedHalftone27 = 0x4,

            /// <summary>
            /// A palette that has 4 intensity levels of each primary: 64-color on-off primaries and the
            /// 16 system colors added. With duplicates removed, 72 colors are available.
            /// </summary>
            FixedHalftone64 = 0x5,

            /// <summary>
            /// A palette that has 5 intensity levels of each primary: 125-color on-off primaries and the
            /// 16 system colors added. With duplicates removed, 133 colors are available.
            /// </summary>
            FixedHalftone125 = 0x6,

            /// <summary>
            /// A palette that has 6 intensity levels of each primary: 216-color on-off primaries and the
            /// 16 system colors added. With duplicates removed, 224 colors are available.
            /// </summary>
            FixedHalftone216 = 0x7,

            /// <summary>
            /// A palette that has 6 intensity levels of each primary: 216-color on-off primaries and the
            /// 16 system colors added. With duplicates removed, 224 colors are available.
            /// </summary>
            FixedWebPalette = FixedHalftone216,

            /// <summary>
            /// A palette that has its 252-color on-off primaries and the 16 system colors added.
            /// With duplicates removed, 256 colors are available.
            /// </summary>
            FixedHalftone252 = 0x8,

            /// <summary>
            /// A palette that has its 256-color on-off primaries and the 16 system colors added.
            /// With duplicates removed, 256 colors are available.
            /// </summary>
            FixedHalftone256 = 0x9,

            /// <summary>
            /// A palette that has 4 shades of gray.
            /// </summary>
            FixedGray4 = 0xa,

            /// <summary>
            /// A palette that has 16 shades of gray.
            /// </summary>
            FixedGray16 = 0xb,

            /// <summary>
            /// A palette that has 256 shades of gray.
            /// </summary>
            FixedGray256 = 0xc,
        };

        /// <summary>
        /// Specifies the type of Windows Imaging Component (WIC) component.
        /// </summary>
        [System::FlagsAttribute]
        public enum class WICComponentType : DWORD
        {
            None = 0,

            /// <summary>
            /// A WIC decoder.
            /// </summary>
            WICDecoder = 0x1,

            /// <summary>
            /// A WIC encoder.
            /// </summary>
            WICEncoder = 0x2,

            /// <summary>
            /// A WIC pixel converter.
            /// </summary>
            WICPixelFormatConverter = 0x4,

            /// <summary>
            /// A WIC metadata reader.
            /// </summary>
            WICMetadataReader = 0x8,

            /// <summary>
            /// A WIC metadata writer.
            /// </summary>
            WICMetadataWriter = 0x10,

            /// <summary>
            /// A WIC pixel format.
            /// </summary>
            WICPixelFormat = 0x20,

            /// <summary>
            /// All WIC components.
            /// </summary>
            WICAllComponents = 0x3f,
        };

        /// <summary>
        /// Specifies the component signing status.
        /// </summary>
        [System::FlagsAttribute]
        public enum class WICComponentSigning : DWORD
        {
            None = 0,

            /// <summary>
            /// A signed component.
            /// </summary>
            Signed = 0x1,

            /// <summary>
            /// An unsigned component
            /// </summary>
            Unsigned = 0x2,

            /// <summary>
            /// A component is safe. Components that do not have a binary component to sign, such as a
            /// pixel format, should return this value.
            /// </summary>
            Safe = 0x4,

            /// <summary>
            /// A component has been disabled.
            /// </summary>
            Disabled = 0x80000000,
        };

        /// <summary>
        /// Contains members that identify a pattern within an image file which can be used to identify
        /// a particular format.
        /// </summary>
        [StructLayoutAttribute(LayoutKind::Explicit, Size = 40)]
        public value struct WICBitmapPattern
        {
        public:
            /// <summary>
            /// The offset the pattern is located in the file.
            /// </summary>
            [FieldOffsetAttribute(0)]
            D2DNet::ULARGE_INTEGER position;

            /// <summary>
            /// The pattern length.
            /// </summary>
            [FieldOffsetAttribute(8)]
            ULONG length;

            /// <summary>
            /// The actual pattern.
            /// </summary>
            [FieldOffsetAttribute(16)]
            BYTE *pattern;

            /// <summary>
            /// The pattern mask.
            /// </summary>
            [FieldOffsetAttribute(24)]
            BYTE *mask;

            /// <summary>
            /// The end of the stream.
            /// </summary>
            [FieldOffsetAttribute(32)]
            bool endOfStream;
        };

        /// <summary>
        /// Specifies the color context types.
        /// </summary>
        public enum class WICColorContextType
        {
            /// <summary>
            /// An uninitialized color context.
            /// </summary>
            Uninitialized = 0,

            /// <summary>
            /// A color context that is a full ICC color profile.
            /// </summary>
            Profile = 0x1,

            /// <summary>
            /// A color context that is one of a number of set color spaces (sRGB, AdobeRGB) that are
            /// defined in the EXIF specification.
            /// </summary>
            ExifColorSpace = 0x2
        };

        /// <summary>
        /// Specifies the cache options available for an encoder.
        /// </summary>
        public enum class WICBitmapEncoderCacheOption
        {
            /// <summary>
            /// The encoder is cached in memory. This option is not supported.
            /// </summary>
            CacheInMemory = 0,

            /// <summary>
            /// The encoder is cached to a temporary file. This option is not supported.
            /// </summary>
            CacheTempFile = 0x1,

            /// <summary>
            /// The encoder is not cached.
            /// </summary>
            NoCache = 0x2,
        };
    }
}