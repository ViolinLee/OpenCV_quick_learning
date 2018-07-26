## TODO: define the convolutional neural network architecture

import torch
from torch.autograd import Variable
import torch.nn as nn
import torch.nn.functional as F
# can use the below import should you choose to initialize the weights of your Net
import torch.nn.init as I


class Net(nn.Module):

    def __init__(self):
        super(Net, self).__init__()
        
        ## TODO: Define all the layers of this CNN, the only requirements are:
        ## 1. This network takes in a square (same width and height), grayscale image as input
        ## 2. It ends with a linear layer that represents the keypoints
        ## it's suggested that you make this last layer output 136 values, 2 for each of the 68 keypoint (x, y) pairs
        
        # As an example, you've been given a convolutional layer, which you may (but don't have to) change:
        # 1 input image channel (grayscale), 32 output channels/feature maps, 5x5 square convolution kernel
        #self.conv1 = nn.Conv2d(1, 32, 5)
        
        ## Note that among the layers to add, consider including:
        # maxpooling layers, multiple conv layers, fully-connected layers, and other layers (such as dropout or batch normalization) to avoid overfitting
        
        # output size = (W - F + 2P)/S + 1
        self.conv1 = nn.Conv2d(1, 32, 5)     # (224-5)/1 + 1 = 220, after maxpool2d --> 110, output size: (32, 110, 110)
        self.conv2 = nn.Conv2d(32, 64, 5)    # (110-5)/1 + 1 = 106, after maxpool2d --> 53, output size: (64, 53, 53)
        self.conv3 = nn.Conv2d(64, 128, 5)     # (53-5)/1 + 1 = 49, after maxpool2d --> 24, output size: (128, 24, 24)
        self.conv4 = nn.Conv2d(128, 128, 5)    # (24-5)/1 + 1 = 20, after maxpool2d --> 10, output size: (128, 10, 10)
        
        self.conv1_bn = nn.BatchNorm2d(32)
        self.conv2_bn = nn.BatchNorm2d(64)
        self.conv3_bn = nn.BatchNorm2d(128)
        self.conv4_bn = nn.BatchNorm2d(128)
         
        self.fc1 = nn.Linear(128 * 10 * 10, 512)
        self.fc1_drop = nn.Dropout(p=0.2)
        
        self.fc2 = nn.Linear(512, 136)
        
        # intialize weights
        for layer in [self.conv1, self.conv2, self.conv3, self.conv4, self.fc1, self.fc2]:
            nn.init.xavier_uniform_(layer.weight)
        
        
    def forward(self, x):
        ## TODO: Define the feedforward behavior of this model
        ## x is the input image and, as an example, here you may choose to include a pool/conv step:
        ## x = self.pool(F.relu(self.conv1(x)))
        
        # a modified x, having gone through all the layers of your model, should be returned
        
        x = F.max_pool2d(F.relu(self.conv1_bn(self.conv1(x))), 2)
        x = F.max_pool2d(F.relu(self.conv2_bn(self.conv2(x))), 2)
        x = F.max_pool2d(F.relu(self.conv3_bn(self.conv3(x))), 2)
        x = F.max_pool2d(F.relu(self.conv4_bn(self.conv4(x))), 2)
        
        x = x.view(x.size(0), -1)
        x = F.relu(self.fc1(x))
        x = self.fc1_drop(x)
        x = self.fc2(x)
        
        return x
