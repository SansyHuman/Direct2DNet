#pragma once

#include "IDirect2DObject.h"
#include "D2DNetHeaders.h"
#include "D2DSettings.h"
#include "Exception/DXException.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        // Done.
        ref class ID2D1Factory;

        /// <summary>
        /// The root class for all resources in Direct2DNet.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("FB9AA369-68D2-4706-B010-035487B6952A")]
        public ref class ID2D1Resource abstract : IDirect2DObject
        {
        internal:
            ::ID2D1Resource *m_pResource;
            Direct2DNet::ID2D1Factory ^m_factory;

        protected:
            ID2D1Resource(Direct2DNet::ID2D1Factory ^factory);

        public:
            ~ID2D1Resource();
            !ID2D1Resource();

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return reinterpret_cast<void *>(m_pResource);
                }
            }

        public:
            /// <summary>
            /// Gets the factory associated with this resource.
            /// </summary>
            property Direct2DNet::ID2D1Factory ^Factory
            {
                Direct2DNet::ID2D1Factory ^get()
                {
                    return m_factory;
                }
            }
        };
    }
}