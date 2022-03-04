#### 基于Wenet训练所得模型的推理代码
- 不依赖torch和torchaudio
- 目前仅测试过CPU端
- 仅支持Linux，python3.7

#### 使用方法
1. 下载整个python目录

2. 安装依赖环境
   ```bash
   pip install -r requirements.txt -i https://pypi.douban.com/simple/
   ```
3. 下载预训练onnx模型到`pretrain_model\20211025_conformer_exp`下,
    - 下载链接：[Google Drive](https://drive.google.com/drive/folders/1Jv9pi44McsGfpFrK9R8zm9ZJuVzlP-uL?usp=sharing)

4. 运行`python test_demo.py`
5. 运行结果如下：
   ```text
    test_data/test.wav      甚至出现交易几乎停滞的情况      0.8272988796234131s
   ```