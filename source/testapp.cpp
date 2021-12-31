#include <stdlib.h>
#include <stdio.h>
#include "libqmasrapi.h"
#define TEST_WAV  "/opt/test/test.wav"

#define MODEL_DIR "/opt/test/models/onnx_20211025_conformer_exp"
int main(int argc, char * argv[])
{


	auto Handle = QmAsr_init(MODEL_DIR, QM_DEFAULT_THREAD_NUM);
	if (!Handle)
	{
		printf("Can't load models from %s\n", MODEL_DIR);
		return -1;
	}

	auto retHandle = QmAsrRecogFile(Handle, TEST_WAV, QASRM_ATTENSION_RESCORING); // QASRM_CTC_GREEDY_SEARCH); // QASRM_ATTENSION_RESCORING);
	int nNumber = QmAsrGetRetNumber(retHandle);
	printf(" %d results.  String:", nNumber);
	const char * szString =QmAsrGetResult(retHandle, 0);
	printf(szString);
	printf("\n");
	if (retHandle)
		QmAsrFreeResult(retHandle);
	QmAsr_Uninit(Handle);
	return 0;


}