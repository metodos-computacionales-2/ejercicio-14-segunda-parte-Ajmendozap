import numpy as np
import matplotlib.pylab as plt

data= np.loadtxt('data_3')
x= data[:,0]; v= data[:,1]; t= data[:,2];

plt.figure(figsize=(10,10))
plt.subplot(2,2,1)
plt.xlabel('$t$');plt.ylabel('$x$')
plt.axvline(c='k',lw=0.9);plt.axhline(c='k',lw=0.9)
plt.plot(t,x)
plt.subplot(2,2,2)
plt.xlabel('$t$');plt.ylabel('$v$')
plt.axvline(c='k',lw=0.9);plt.axhline(c='k',lw=0.9)
plt.plot(t,-v-50)
plt.savefig('Euler solution.png')