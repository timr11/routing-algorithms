from math import log2
from matplotlib import pyplot
probs = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
info = [-log2(p) for p in probs]
pyplot.plot(probs, info, marker='.')
pyplot.title('Probability vs Information')
pyplot.xlabel('Probability');
pyplot.ylabel('Information');
pyplot.show()
