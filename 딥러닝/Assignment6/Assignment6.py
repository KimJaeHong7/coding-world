import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
import os
os.environ['KMP_DUPLICATE_LIB_OK']='True'
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets("./mnist/data/",one_hot=True)

batch_size = 100
learning_rate = 0.01
noise_level = 1.0
epoch_num = 20
n_input = 28*28
n_hidden1 = 256
n_hidden2 = 128
X = tf.placeholder(tf.float32, [None, n_input])

W_encoder1 = tf.Variable(tf.random_uniform([n_input, n_hidden1],-1.,1.))
b_encoder1 = tf.Variable(tf.random_uniform([n_hidden1],-1.,1.))

encoder_h1 = tf.nn.sigmoid(tf.add(tf.matmul(X+noise_level*tf.random_normal(tf.shape(n_input)), W_encoder1),b_encoder1))

W_encoder2 = tf.Variable(tf.random_uniform([n_hidden1, n_hidden2],-1.,1.))
b_encoder2 = tf.Variable(tf.random_uniform([n_hidden2],-1.,1.))

encoder_h2 = tf.nn.sigmoid(tf.add(tf.matmul(encoder_h1, W_encoder2),b_encoder2))

W_decoder1 = tf.Variable(tf.random_uniform([n_hidden2, n_hidden1],-1.,1.))
b_decoder1 = tf.Variable(tf.random_uniform([n_hidden1],-1.,1.))

decoder = tf.nn.sigmoid(tf.add(tf.matmul(encoder_h2, W_decoder1),b_decoder1))

W_decoder2 = tf.Variable(tf.random_uniform([n_hidden1, n_input],-1.,1.))
b_decoder2 = tf.Variable(tf.random_uniform([n_input],-1.,1.))

output = tf.nn.sigmoid(tf.add(tf.matmul(decoder, W_decoder2),b_decoder2))

cost = tf.reduce_mean(tf.square(X-output))
opt = tf.train.AdamOptimizer(learning_rate).minimize(cost)

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    total_batch = int(mnist.train.num_examples/batch_size)

    for epoch in range(epoch_num):
        avg_cost = 0
        for i in range(total_batch):
            batch_xs, batch_ys = mnist.train.next_batch(batch_size)
            _, cost_val =  sess.run([opt, cost], feed_dict={X: batch_xs})
            avg_cost+=cost_val/total_batch
        print('Epoch: ', '%d'%(epoch+1), 'cost: ', '{:.9f}'.format(avg_cost))

    samples = sess.run(output, feed_dict={X: mnist.test.images[:10]})
    fig, ax = plt.subplots(2, 10, figsize=(10,2))

    for i in range(10):
        ax[0][i].set_axis_off()
        ax[1][i].set_axis_off()
        ax[0][i].imshow(np.reshape(mnist.test.images[i],(28,28)))
        ax[1][i].imshow(np.reshape(samples[i],(28,28)))
    plt.show()