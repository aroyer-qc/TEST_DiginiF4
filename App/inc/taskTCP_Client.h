//-------------------------------------------------------------------------------------------------
//
//  File : taskTCP_CLient.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2026 Alain Royer.
// Email: aroyer.qc@gmail.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
// AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------
// Global Macro
//-------------------------------------------------------------------------------------------------

#ifdef TASK_TCP_CLIENT_GLOBAL
    #define TASK_TCP_CLIENT_EXTERN
#else
    #define TASK_TCP_CLIENT_EXTERN extern
#endif

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define TASK_TCP_CLIENT_STACK_SIZE               256
#define TASK_TCP_CLIENT_PRIO                     4

//-------------------------------------------------------------------------------------------------
// Class definition(s)
//-------------------------------------------------------------------------------------------------

class TCP_Client
{
    public:

        void            Run                         (void);
        SystemState_e   Initialize                  (void);
        void            GiveToRun                   (void)      { nOS_SemGive(&m_Sem); }

    private:

        static nOS_Thread      m_Handle;
        static nOS_Stack       m_Stack          [TASK_TCP_CLIENT_STACK_SIZE];
        
        TCP_Socket             m_Socket;
};

//-------------------------------------------------------------------------------------------------
// Global variable(s) and constant(s)
//-------------------------------------------------------------------------------------------------

TASK_TCP_CLIENT_EXTERN   class ClassTCP_Client    TaskTCP_Client;

#ifdef TASK_TCP_CLIENT_GLOBAL
                    class ClassTCP_Client*  pTaskTCP_Client = &TaskTCP_Client;
#else
    extern          class ClassTCP_Client*  pTaskTCP_Client;
#endif

//-------------------------------------------------------------------------------------------------
// Function prototype(s)
//-------------------------------------------------------------------------------------------------

extern "C" void TaskTCP_Client_Wrapper           (void* pvParameters);

//-------------------------------------------------------------------------------------------------