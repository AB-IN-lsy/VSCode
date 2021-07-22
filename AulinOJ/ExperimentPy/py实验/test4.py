import numpy as np
import matplotlib.pyplot as plt
import matplotlib
matplotlib.rcParams['font.family'] = 'SimHei'
matplotlib.rcParams['font.sans-serif'] = ['SimHei']

plt.subplot(211)
plt.title('2-1-1 subplots-区域')
plt.ylabel('衰减的震荡')
plt.xticks(np.linspace(0, 5, 6))
plt.yticks(np.linspace(-0.5, 1, 4))
x = np.linspace(0, 5, 50)
y = np.cos(2 * np.pi * x) * np.exp(-x)
plt.plot(x, y, 'k', color = '#054E9F', linewidth = 1, linestyle = "-", marker = 'o')

plt.subplot(212)
plt.title('2-1-2 subplots-区域')
plt.xlabel('时间(s)')
plt.ylabel('sin函数')
plt.xticks(np.linspace(0.00, 2.00, 9))
plt.yticks(np.linspace(-1.0, 1, 5))
x = np.linspace(0, 2, 50)
y = np.sin(2 * np.pi *x)
plt.plot(x, y, 'k', color = '#054E9F', linewidth = 1, linestyle = "-", marker = 'o')
plt.show()