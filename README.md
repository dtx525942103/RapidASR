# RapidASR: a new member of RapidAI family.

- Our vision is to offer an out-of-box engineering implementation for ASR.

- A cpp implementation of recognize-onnx.py in [Wenet-asr](https://github.com/wenet-e2e/wenet) in which it implements the inference with ONNXRuntime. 

- For a version of pure CPP code, we need to do a bit of work to rewrite some components.

- Special thanks to its original author SlyneD.

- Less is more. Less dependency, more usability.

- Just offline mode, not support stream mode, aka separate files can be recognized.

## Supported modes:
- CTC_GREEDY_SEARCH
- CTC_RPEFIX_BEAM_SEARCH
- ATTENSION_RESCORING 

## Progress:
- [X] [Python](./python)
- [x] Linux
- [x] Mac
- [x] Android
- [ ] Windows

## Models

- The model is original from [wenetspeech/s0](https://github.com/wenet-e2e/wenet/tree/main/examples/wenetspeech/s0) and tested with `recognize-onnx.py`.

- Download [Bidirectional model](http://mobvoi-speech-public.ufile.ucloud.cn/public/wenet/wenetspeech/20211025_conformer_bidecoder_exp.tar.gz)

- Download:
    - URL：https://pan.baidu.com/s/1BTR-uR_8WWBFpvOisNR_PA 
    - Extract code：9xjz 

Sample Rate: 16000Hz

Sample Depth: 16bits

Channel: single

## Build

- Linux 
 ```
Visual studio 2019 & cmake 3.20

 cd thirdpart
 build_win.cmd x86|x64
 ```

  TBD
- Windows

## Notice:
The project is under the protection of GPL V2, Apache license and commercial license.

For so/dll/c++ interface, it complies with GPL V2.

For python interface, it belongs to Apache license.

For a commercial license, please contact us: znsoft@163.com (commercial license only).

## Commercial support

For a commercial user, we offer a library to resample input data including mp3, mp4, mkv  and so on.

Please visit: https://github.com/RapidAI/RapidAudioKit
