#include "ID2D1Multithread.h"

namespace D2DNet
{
    namespace Direct2DNet
    {
        ID2D1Multithread::ID2D1Multithread(::ID2D1Multithread *pThread) : m_pThread(pThread)
        {
            
        }

        ID2D1Multithread::~ID2D1Multithread()
        {
            this->!ID2D1Multithread();
        }

        ID2D1Multithread::!ID2D1Multithread()
        {
            if(m_pThread)
            {
                m_pThread->Release();
                m_pThread = nullptr;
            }
        }

        bool ID2D1Multithread::Equals(System::Object ^other)
        {
            try
            {
                return this->m_pThread == safe_cast<Direct2DNet::ID2D1Multithread ^>(other)->m_pThread;
            }
            catch(System::Exception ^)
            {
                return false;
            }
        }

        void ID2D1Multithread::Enter()
        {
            m_pThread->Enter();
        }

        void ID2D1Multithread::Leave()
        {
            m_pThread->Leave();
        }

    }
}