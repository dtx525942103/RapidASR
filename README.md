# RapidASR
A cpp implementation of wenet-onnx




the model is original from https://github.com/wenet-e2e/wenet/tree/main/examples/wenetspeech/s0



执行转换脚本：

cd wenet
export PYTHONPATH=/root/wenet-onnx/wenet
cd wenet/bin/
python export_onnx.py 
