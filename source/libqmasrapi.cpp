#include "precomp.h"

#ifdef __cplusplus 

extern "C" {
#endif


	// APIs for qmasr


	_QMASRAPI QMASR_HANDLE  QmAsr_init(const char* szModelDir,int nThread)
	{
		
		CQmASRRecog* pObj = new CQmASRRecog(szModelDir, nThread);
		if (pObj)
		{
			if (pObj->IsLoaded())
				return pObj;
			else
				delete pObj;

		}
	
		return nullptr;
	}


	_QMASRAPI QMASR_RESULT QmAsrRecogBuffer(QMASR_HANDLE handle, const char* szBuf, int nLen, QMASR_MODE Mode)
	{

		
		CQmASRRecog* pRecogObj = (CQmASRRecog*)handle;

		if (!pRecogObj)
			return nullptr;
		vector<float>  wav;
	
		wenet::WavReaderMem Reader(szBuf,nLen, wav);

		assert(Reader.sample_rate() == Reader.sample_rate());
		wenet::FeaturePipelineConfig config(QM_FEATURE_DIMENSION, QM_DEFAULT_SAMPLE_RATE); 
		vector<vector<float>> feats;
		if (pRecogObj->ExtractFeature(wav, feats, config) > 0)
			return pRecogObj->DoRecognize(feats, Mode);
		else
			return nullptr;
	}

	_QMASRAPI QMASR_RESULT QmAsrRecogFile(QMASR_HANDLE handle, const char* szWavfile, QMASR_MODE Mode)
	{
		CQmASRRecog* pRecogObj = (CQmASRRecog*)handle;

		if (!pRecogObj)
			return nullptr;
				
		vector<float>  wav;
		wenet::WavReader Reader(szWavfile, wav);
		assert(Reader.sample_rate() == Reader.sample_rate());
		wenet::FeaturePipelineConfig config(QM_FEATURE_DIMENSION, Reader.sample_rate());
		vector<vector<float>> feats;
		if (pRecogObj->ExtractFeature(wav, feats,config) > 0)
			return pRecogObj->DoRecognize(feats,Mode);
		else
			return nullptr;
	}

	_QMASRAPI const int QmAsrGetRetNumber(QMASR_RESULT Result)
	{
		if (!Result)
			return 0;
		PQMASR_RECOG_RESULT pResult = (PQMASR_RECOG_RESULT)Result;
		return pResult->Strings.size();
		
	}
	_QMASRAPI const char* QmAsrGetResult(QMASR_RESULT Result,int nIndex)
	{
		PQMASR_RECOG_RESULT pResult = (PQMASR_RECOG_RESULT)Result;
		if(!pResult)
			return nullptr;
		if (nIndex >= pResult->Strings.size())
			return nullptr;
		return pResult->Strings[nIndex].c_str();
	}

	_QMASRAPI void QmAsrFreeResult(QMASR_RESULT Result)
	{

		if (Result)
		{
			delete PQMASR_RECOG_RESULT(Result);

		}
	}

	_QMASRAPI void QmAsr_Uninit(QMASR_HANDLE handle)
	{

		CQmASRRecog* pRecogObj = (CQmASRRecog*)handle;

		if (!pRecogObj)
			return;

		delete pRecogObj;

	}



#ifdef __cplusplus 

}
#endif

