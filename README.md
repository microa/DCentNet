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

#### 2. Receiver (BLE)

- **Connected Mode**:  
  [Code: `rec.cpp`](Code/rec.cpp)

- **Broadcast Mode**:  
  _(updating...)_

---
 
### Deploy in Embedded System

- **Trained Model**:  
  [Download: `2Layerswith96%Acc.zip`](inference/2Layerswith96%Acc.zip)

#### Steps for Deployment:
1. Launch Arduino IDE (Version used: `2.3.3`).
2. Navigate to `Sketch` -> `Include Library` -> `Add .ZIP Library` -> (Add the above-trained model).
3. Go to `Tools` -> `Manage Libraries` -> Search for "ArduinoBLE" -> Install (Version used: `1.3.7`).
4. Include the inference file in your code (see the code example under [Experimental Code - Inference Mode](#1-inference-and-sender-ble)).

#### Alternative Trained Models:
- [EEPS-2LayerCNN.zip](inference/EEPS-2LayerCNN.zip)
- [EEPS-3LayerCNN.zip](inference/EEPS-3LayerCNN.zip)
- [EEPS-4LayerCNN.zip](inference/EEPS-4LayerCNN.zip)
- [EEPS-5LayerCNN.zip](inference/EEPS-5LayerCNN.zip)

---

### Training Code

- **Simple Version**:  
  [Code: `eeps-train.ipynb`](Code/eeps-train.ipynb)

#### Instructions:
- Register on Edge Impulse and obtain an API key (free for personal use).
- Replace the placeholder in the training code with your API key.
- You can customize and replace the network for your specific use case.  

Enjoy training your model!

---

### Replicate Guide <br>
- **Support**:  
  If you have any questions, feel free to email me at [bh.huang@ieee.org](mailto:bh.huang@ieee.org). I will address your questions and update the guide as needed.


---

### Citation

- **Support**: 
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



