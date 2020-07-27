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
        [System::Runtime::InteropServices::GuidAttribute("2cd90691-12e2-11dc-9fed-001143a055f9")]
        public ref class ID2D1Resource abstract : IDirect2DObject
        {
        internal:
            ::ID2D1Resource *m_pResource;
            Direct2DNet::ID2D1Factory ^m_factory;

            ID2D1Resource() : m_pResource(nullptr), m_factory(nullptr) {}

        protected:
            ID2D1Resource(Direct2DNet::ID2D1Factory ^factory);

        public:
            ~ID2D1Resource();
            !ID2D1Resource();

            virtual bool Equals(System::Object ^other) override;

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return reinterpret_cast<void *>(m_pResource);
                }
            }

        public:
            virtual void HandleCOMInterface(void *obj);

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