## DCentNet (Decentralized Signal Classification using Early Exit)

### Experimental Code

#### 1. Inference and Sender (BLE)

- **Deep Sleep Mode**:  
  [Code: `DeepSleep(idle_mode).cpp`](Code/DeepSleep(idle_mode).cpp)

- **Inference Mode**:  
  [Code: `bk_vtx001_noBLE_Infer_noidle.cpp`](Code/bk_vtx001_noBLE_Infer_noidle.cpp)

- **Inference Idle Mode**:  
  [Code: `bk_vtx001_noBLE_Infer_idle.cpp`](Code/bk_vtx001_noBLE_Infer_idle.cpp)

- **Connected Mode**:  
  [Code: `bk_vtx001a_connected_noinfer_idle_keepconnected.cpp`](Code/bk_vtx001a_connected_noinfer_idle_keepconnected.cpp)

- **Broadcast Mode**:  
  [Code: `bk_v009a_2DenseOutput_Broadcast_realclass.cpp`](Code/bk_v009a_2DenseOutput_Broadcast_realclass.cpp)

---

#### 2. Receiver (BLE)

- **Connected Mode**:  
  _(Code reference not provided)_

- **Broadcast Mode**:  
  _(Code reference not provided)_

 
### Deploy in Embedded System <br>
Trained model: [2Layerswith96%Acc.zip](inference/2Layerswith96%Acc.zip) <br>
Step1. Launch Arduino IDE (my version is 2.3.3) <br>
Step2. Sketch -> Include Library -> Add .ZIP Library -> (add above trained model) <br>
Step3. Tools -> Manage Libraries -> search "ArduinoBLE" -> install (my version is 1.3.7) <br>
Step4. Include the inference file on your code (code example provided above, see Experimental Code - Inference mode) <br>
Alternative trained models: <br>
[EEPS-2LayerCNN.zip](inference/EEPS-2LayerCNN.zip) <br>
[EEPS-3LayerCNN.zip](inference/EEPS-3LayerCNN.zip) <br>
[EEPS-4LayerCNN.zip](inference/EEPS-4LayerCNN.zip) <br>
[EEPS-5LayerCNN.zip](inference/EEPS-5LayerCNN.zip) <br>

### Training Code <br>
Simple version: [code](Code/eeps-train.ipynb) <br>
To use the training code, you need to register on Edge Impulse and obtain an API key (free for personal use). <br>
Once you have the API key, replace the placeholder in the code with it. <br> 
And you can also replace the network for your own use. <br> 
Enjoy it! <br> 

### Replicate Guide <br>
Q0. If I receive any questions via email(bh.huang@ieee.org), I will solve them and update them here. <br>



* If you find our article is useful to your research, please cite following papers: <br>
```bibtex
@article{LI2025107468,
  title = {DCentNet: Decentralized multistage biomedical signal classification using early exits},
  journal = {Biomedical Signal Processing and Control},
  volume = {104},
  pages = {107468},
  year = {2025},
  issn = {1746-8094},
  doi = {https://doi.org/10.1016/j.bspc.2024.107468},
  url = {https://www.sciencedirect.com/science/article/pii/S174680942401526X},
  author = {Xiaolin Li and Binhua Huang and Barry Cardiff and Deepu John},
}
```



