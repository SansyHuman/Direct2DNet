#pragma once

namespace D2DNet
{
    namespace ComIO
    {
        public enum class BSOS_OPTIONS : DWORD
        {
            /// <summary>
            /// When creating a byte seeker over a stream, base randomaccessstream behavior on the STGM
            /// mode from IStream::Stat.
            /// </summary>
            DEFAULT = 0,

            /// <summary>
            /// In addition, utilize IDestinationStreamFactory::GetDestinationStream.
            /// </summary>
            PREFERDESTINATIONSTREAM
        };

        [System::FlagsAttribute]
        public enum class STGC : DWORD
        {
            DEFAULT = 0,
            OVERWRITE = 1,
            ONLYIFCURRENT = 2,
            DANGEROUSLYCOMMITMERELYTODISKCACHE = 4,
            CONSOLIDATE = 8
        };

        [System::FlagsAttribute]
        public enum class LOCKTYPE : DWORD
        {
            LOCK_WRITE = 1,
            LOCK_EXCLUSIVE = 2,
            LOCK_ONLYONCE = 4
        };

        [System::FlagsAttribute]
        public enum class STATFLAG
        {
            DEFAULT = 0,
            NONAME = 1,
            NOOPEN = 2
        };
    }
}