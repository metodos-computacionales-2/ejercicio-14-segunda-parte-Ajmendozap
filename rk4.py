import numpy as np
import matplotlib.pylab as plt

data= np.loadtxt('data_rk4.dat')
t= data[:,0]; x= data[:,1]; v= data[:,2]; xf= data[:,3]

plt.figure(figsize=(15,15))
plt.suptitle('Runge-Kutta Solution')
plt.subplot(2,2,1)
plt.xlabel('$t$');plt.ylabel('$x$')
plt.axvline(c='k',lw=0.9);plt.axhline(c='k',lw=0.9)
plt.plot(t,x)
plt.subplot(2,2,2)
plt.xlabel('$t$');plt.ylabel('$v$')
plt.axvline(c='k',lw=0.9);plt.axhline(c='k',lw=0.9)
plt.plot(t,v)
plt.savefig('rk4 solution.png')
plt.figure(figsize=(10,10))
plt.title('rk4 con fricción')
plt.xlabel('$t$');plt.ylabel('$x$')
plt.axvline(c='k',lw=0.9);plt.axhline(c='k',lw=0.9)
plt.plot(t,x*np.cumsum(xf))
plt.savefig('rk4sol_friction.png')