#pragma once

#include "DWNetHeaders.h"

namespace D2DNet
{
    namespace DWriteNet
    {

#ifndef DWNET_ERR
#define DWNET_ERR(x) literal HRESULT E_ ## x = DWRITE_E_ ## x
#endif

#ifdef E_UNEXPECTED
#undef E_UNEXPECTED
#endif

        /// <summary>
        /// Contains DirectWrite error codes.
        /// </summary>
        public ref class DWriteError abstract sealed
        {
        public:
            /// <summary>
            /// Indicates an error in an input file such as a font file.
            /// </summary>
            DWNET_ERR(FILEFORMAT);

            /// <summary>
            /// Indicates an error originating in DirectWrite code, which is not expected to occur but is
            /// safe to recover from.
            /// </summary>
            DWNET_ERR(UNEXPECTED);

            /// <summary>
            /// Indicates the specified font does not exist.
            /// </summary>
            DWNET_ERR(NOFONT);

            /// <summary>
            /// A font file could not be opened because the file, directory, network location, drive, or
            /// other storage location does not exist or is unavailable.
            /// </summary>
            DWNET_ERR(FILENOTFOUND);

            /// <summary>
            /// A font file exists but could not be opened due to access denied, sharing violation, or
            /// similar error.
            /// </summary>
            DWNET_ERR(FILEACCESS);

            /// <summary>
            /// A font collection is obsolete due to changes in the system.
            /// </summary>
            DWNET_ERR(FONTCOLLECTIONOBSOLETE);

            /// <summary>
            /// The given interface is already registered.
            /// </summary>
            DWNET_ERR(ALREADYREGISTERED);

            /// <summary>
            /// The font cache contains invalid data.
            /// </summary>
            DWNET_ERR(CACHEFORMAT);

            /// <summary>
            /// A font cache file corresponds to a different version of DirectWrite.
            /// </summary>
            DWNET_ERR(CACHEVERSION);

            /// <summary>
            /// The operation is not supported for this type of font.
            /// </summary>
            DWNET_ERR(UNSUPPORTEDOPERATION);

            /// <summary>
            /// The version of the text renderer interface is not compatible.
            /// </summary>
            DWNET_ERR(TEXTRENDERERINCOMPATIBLE);

            /// <summary>
            /// The flow direction conflicts with the reading direction. They must be perpendicular to
            /// each other.
            /// </summary>
            DWNET_ERR(FLOWDIRECTIONCONFLICTS);

            /// <summary>
            /// The font or glyph run does not contain any colored glyphs.
            /// </summary>
            DWNET_ERR(NOCOLOR);

            /// <summary>
            /// A font resource could not be accessed because it is remote.
            /// </summary>
            DWNET_ERR(REMOTEFONT);

            /// <summary>
            /// A font download was canceled.
            /// </summary>
            DWNET_ERR(DOWNLOADCANCELLED);

            /// <summary>
            /// A font download failed.
            /// </summary>
            DWNET_ERR(DOWNLOADFAILED);

            /// <summary>
            /// A font download request was not added or a download failed because there are too many
            /// active downloads.
            /// </summary>
            DWNET_ERR(TOOMANYDOWNLOADS);
        };

#ifndef E_UNEXPECTED
#define E_UNEXPECTED                     _HRESULT_TYPEDEF_(0x8000FFFFL)
#endif
    }
}