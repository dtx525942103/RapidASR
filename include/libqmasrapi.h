#pragma once


#ifdef WIN32


#ifdef D_QMASR_API_EXPORT

#define  _QMASRAPI __declspec(dllexport)
#else
#define  _QMASRAPI __declspec(dllimport)
#endif
	

#else
#define _QMASRAPI  
#endif


#ifdef __cplusplus 

extern "C" {
#endif

typedef void* QMASR_HANDLE;

typedef void* QMASR_RESULT;

typedef unsigned char QMASR_BOOL;

#define QMASR_TRUE 1
#define QMASR_FALSE 0
#define QM_DEFAULT_THREAD_NUM  4


typedef enum
{
 QASRM_CTC_GREEDY_SEARCH=0,
 QASRM_CTC_RPEFIX_BEAM_SEARCH = 1,
 QASRM_ATTENSION_RESCORING = 2,
 
}QMASR_MODE;
	
	// APIs for qmasr

_QMASRAPI QMASR_HANDLE  QmAsr_init(const char* szModelDir, int nThread);


_QMASRAPI QMASR_RESULT QmAsrRecogBuffer(QMASR_HANDLE handle, const char* szBuf, int nLen, QMASR_MODE Mode);
_QMASRAPI QMASR_RESULT QmAsrRecogFile(QMASR_HANDLE handle, const char* szWavfile, QMASR_MODE Mode);

_QMASRAPI const char* QmAsrGetResult(QMASR_RESULT Result,int nIndex);

_QMASRAPI const int QmAsrGetRetNumber(QMASR_RESULT Result);
_QMASRAPI void QmAsrFreeResult(QMASR_RESULT Result);


_QMASRAPI void QmAsr_Uninit(QMASR_HANDLE Handle);





#ifdef __cplusplus 

}
#endif