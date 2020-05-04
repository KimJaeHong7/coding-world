import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
import math
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets("MNIST_data/", one_hot=True)

x,y = mnist.train.next_batch(3)
for i in range(3):
    mnist_image = np.array(x[i]).reshape((28,28))

    plt.title("label : " + str(np.where(y[i] == 1)[0][0]))
    plt.imshow(mnist_image, cmap="gray")
    plt.show()