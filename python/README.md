#### 基于Wenet训练所得模型的推理代码
- 不依赖torch和torchaudio
- 目前仅测试过CPU端
- 仅支持Linux，python3.7

#### 使用方法
1. 下载整个python目录

2. 安装依赖环境
   - 批量安装
    ```bash
    pip install -r requirements.txt -i https://pypi.douban.com/simple/
    ```
    - 因为`_swig_decoders.cpython-37m-x86_64-linux-gnu.so`依赖包比较大，也放在了谷歌网盘下，请移步这里[下载](https://drive.google.com/file/d/1mt4WinNb_OfXOgz8XoA0URxsQ1JSurKm/view?usp=sharing)。下载之后放在`python/wenet/swig_decoders`下

3. 下载预训练onnx模型到`pretrain_model\20211025_conformer_exp`下,
    - 下载链接：[Google Drive](https://drive.google.com/drive/folders/1Jv9pi44McsGfpFrK9R8zm9ZJuVzlP-uL?usp=sharing)
    - 最终结构目录如下，请自行比对：
        ```text
        .
        ├── pretrain_model
        │   └── 20211025_conformer_exp
        │       ├── decoder.onnx
        │       ├── encoder.onnx
        │       ├── test.yaml
        │       └── words.txt
        ├── README.md
        ├── requirements.txt
        ├── test_data
        │   └── test.wav
        ├── test_demo.py
        └── wenet
            ├── __init__.py
            ├── kaldifeat
            │   ├── feature.py
            │   ├── __init__.py
            │   ├── ivector.py
            │   ├── LICENSE
            │   └── README.md
            ├── swig_decoders
            │   ├── __init__.py
            │   ├── _swig_decoders.cpython-37m-x86_64-linux-gnu.so
            │   ├── _swig_decoders.py
            │   └── swig_decoders.py
            ├── utils.py
            └── wenet_infer.py
        ```


4. 运行`python test_demo.py`
5. 运行结果如下：
   ```text
    test_data/test.wav      甚至出现交易几乎停滞的情况      0.8272988796234131s
   ```