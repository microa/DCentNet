## DSCEE (Decentralized Signal Classification using Early Exit)

### Experimental Code <br>
Deep sleep mode: [code](Code/DeepSleep(idle_mode).cpp) <br>
Inference mode: [code](Code/bk_vtx001_noBLE_Infer_noidle.cpp) <br>
Inference idle mode: [code](Code/bk_vtx001_noBLE_Infer_idle.cpp) <br>
Connected mode: [code](Code/bk_vtx001a_connected_noinfer_idle_keepconnected.cpp) <br>
Broadcast mode: [code](Code/bk_v009a_2DenseOutput_Broadcast_realclass.cpp). <br> 
 
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
To be continue... <br>

### Replicate Guide <br>
To be continue... <br>



* If you find our article is useful to your research, please cite following papers: <br>
```bibtex
@inproceedings{xiaolin2024,
  title={DCentNet: Decentralized Multistage Biomedical Signal Classification using Early Exits},
  author={Xiaolin Li, Binhua Huang, Barry Cardiff, Deepu John},
  booktitle={Biomedical Signal Processing and Control},
  pages={100--120},
  year={2024},
  organization={NONE}
}
```

<!-- 
```
Once the paper is accepted, we will release the citation details.
```
-->

