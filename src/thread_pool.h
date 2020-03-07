/*
Copyright (c) 2019, Yongxin He<manexport@yeah.net>. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef THREAD_POOL_STATICLIB
#  define THREAD_POOL_EXTERN
#elif defined(_WIN32)					 
#  ifdef THREAD_POOL_EXPORTS
#    define THREAD_POOL_EXTERN __declspec(dllexport)
#  else /* !THREAD_POOL_EXPORTS */
#    define THREAD_POOL_EXTERN __declspec(dllimport)
#  endif /* !THREAD_POOL_EXPORTS */
#else    /* !defined(_WIN32) */
#  ifdef THREAD_POOL_EXPORTS
#    define THREAD_POOL_EXTERN __attribute__((visibility("default")))
#  else /* !THREAD_POOL_EXPORTS */
#    define THREAD_POOL_EXTERN
#  endif /* !THREAD_POOL_EXPORTS */
#endif   /* !defined(_WIN32) */

#define bool	                _Bool
#define false	                (0)
#define true	                (1)
#define RB_TRUE                 (1)
#define RB_FALSE                (0)
#define TASK_MAX              (100)
	typedef void *thread_pool_t;
#ifdef _WIN64
	typedef unsigned long long ullt;
#else 
	typedef unsigned long ullt;
#endif
	THREAD_POOL_EXTERN ullt thread_pool_create();
	THREAD_POOL_EXTERN bool thread_pool_reset(const thread_pool_t  thd);
	THREAD_POOL_EXTERN bool thread_pool_destroy(const thread_pool_t thd);
#ifdef __cplusplus
}
#endif
#endif // __THREAD_POOL_H__