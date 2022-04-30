#### 基于Wenet训练所得模型的推理代码
- 项目来源：[wenet/aishell/s0](https://github.com/wenet-e2e/wenet/blob/main/examples/aishell/s0/README.md)
- 运行环境：Python 3.7 | CPU | 不依赖torch和torchaudio
   ```text
   # 编译系统信息
   LSB Version:    :core-4.1-amd64:core-4.1-noarch
   Distributor ID: CentOS
   Description:    CentOS Linux release 7.9.2009 (Core)
   Release:        7.9.2009
   Codename:       Core
   ```

#### 使用方法
1. 下载整个`python/base_wenet`目录

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

#### 模型转onnx代码
```bash
# python3.7 torch1.10
root_dir="examples/mix_data/exp/conformer/2022-04-07-05-37-18"
config_path="${root_dir}/train.yaml"
cmvn_file="${root_dir}/global_cmvn"
checkpoint_path="${root_dir}/4.pt"
dir_name=${checkpoint_path##*/}
dir_name=${dir_name%.*}
out_onnx_dir="export_onnx/mix_data/${dir_name}"

python wenet/bin/export_onnx.py --config ${config_path} \
                      --checkpoint ${checkpoint_path} \
                      --cmvn_file ${cmvn_file} \
                      --output_onnx_dir ${out_onnx_dir}

```
