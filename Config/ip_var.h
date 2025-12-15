//-------------------------------------------------------------------------------------------------
//
//  File :  ip_var.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2024 Alain Royer.
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
//
// Note(s)      Since there can be multiple instance of IP_Manager, Stack must be declare outside
//              the class so it can be located in a proper memory region like the CCMRAM on the F4
//
//-------------------------------------------------------------------------------------------------

#ifdef LIB_IP_MANAGER_GLOBAL

//nOS_Stack           WiredIP_Stack[TASK_IP_MANAGER_STACK_SIZE]     NOS_STACK_LOCATION;
//IP_Manager          myWiredIP(&WiredIP_Stack[0]);

#else

//extern IP_Manager   myWiredIP;

#endif

//-------------------------------------------------------------------------------------------------

