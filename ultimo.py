import numpy as np
import matplotlib.pyplot as plt
import os

os.system("g++ 30.cpp")
os.system("./a.out")


pinocho = np.loadtxt("JaimePongameCinco.dat")
x=np.linspace(0,200,len(pinocho))
a=np.linspace(1,len(pinocho[0]),len(pinocho[0]))
plt.figure(figsize=(20,10))
plt.subplot(121)

plt.imshow(pinocho)
plt.colorbar(label="Temperatura")
plt.ylabel("Indice T")
plt.xlabel("Indice X")

plt.subplot(122)
plt.plot(a,pinocho[0])
plt.plot(a,pinocho[-1])
plt.ylabel("Temperatura")
plt.xlabel("Indice X")
plt.legend()

plt.savefig("graficas.png")










