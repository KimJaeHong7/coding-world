import tensorflow as tf
import numpy as np
x_data = [[0,0],[0,1],[1,0],[1,1]]
y_data = [[0],[1],[1],[0]]

keep_prob = tf.placeholder(tf.float32)
X = tf.placeholder(tf.float32, [None,2])
Y = tf.placeholder(tf.float32, [None,1])

W = tf.Variable(tf.random_uniform([2,3],-1,0,1,0))
b = tf.Variable(tf.random_uniform([3],-1,0,1,0))

layer1 = tf.sigmoid(tf.add(tf.matmul(X,W),b))
layer1 = tf.nn.dropout(layer1, keep_prob)
W2 = tf.Variable(tf.random_uniform([3,1],-1.0,1.0))
b2 = tf.Variable(tf.random_uniform([1],-1.0,1.0))

hypothesis = tf.sigmoid(tf.add(tf.matmul(layer1,W2),b2))
cost = -tf.reduce_mean(Y * tf.log(hypothesis) + (1 - Y) * tf.log(1 - hypothesis))
opt = tf.train.GradientDescentOptimizer(learning_rate = 0.1)
train_op = opt.minimize(cost)

with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())

    for step in range(1000):
        for x, y in zip(x_data,y_data):
            sess.run([train_op,cost],feed_dict={X:[x],Y:[y]})
    
    print(sess.run(hypothesis, feed_dict={X:x_data}))