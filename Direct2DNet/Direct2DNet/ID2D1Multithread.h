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

        /// <summary>
        /// A locking mechanism from a Direct2D factory that Direct2D uses to control
        /// exclusive resource access in an app that is uses multiple threads.
        /// </summary>
        [System::Runtime::InteropServices::GuidAttribute("31e6e7bc-e0ff-4d46-8c64-a0a8c41c15d3")]
        public ref class ID2D1Multithread : Direct2DNet::IDirect2DObject
        {
        private:
            ::ID2D1Multithread *m_pThread;

        internal:
            ID2D1Multithread() : m_pThread(nullptr) {}

            ID2D1Multithread(::ID2D1Multithread *pThread);

        public:
            ~ID2D1Multithread();
            !ID2D1Multithread();

            virtual bool Equals(System::Object ^other) override;

            virtual property void *NativePointer
            {
                virtual void *get()
                {
                    return m_pThread;
                }
            }

            virtual void HandleCOMInterface(void *obj);

            /// <summary>
            /// Gets whether the D2D factory was created with
            ///<see cref="Direct2DNet::D2D1_FACTORY_TYPE::MULTI_THREADED"/>.
            /// </summary>
            property bool MultithreadProtected
            {
                bool get()
                {
                    return System::Convert::ToBoolean(m_pThread->GetMultithreadProtected());
                }
            }

            /// <summary>
            /// Enters the D2D API critical section, if it exists.
            /// </summary>
            void Enter();

            /// <summary>
            /// Leaves the D2D API critical section, if it exists.
            /// </summary>
            void Leave();
        };
    }
}