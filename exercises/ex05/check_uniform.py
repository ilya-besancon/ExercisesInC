#!/usr/bin/python

"""Read floating point values and plot their CDF.

Copyright 2016 Allen B. Downey
License: GNU GPLv3 http://www.gnu.org/licenses/gpl.html
"""

from __future__ import print_function, division

import sys

import numpy as np
import matplotlib.pyplot as plt

from collections import Counter


def read_data(fp):
    return [float(line.rstrip()) for line in fp]


def main(script, filename=None):
    if filename is None:
        fp = sys.stdin
    else:
        fp = open(filename)

    t = read_data(fp)
    counter = Counter(t)

<<<<<<< HEAD
    xs = counter.keys()
    # xs.sort()
    xs = sorted(xs)

    # ys = np.cumsum(counter.values(), dtype=float)  # .astype(float)
    ys = np.cumsum(counter.values()).astype(float)
=======
    xs = list(counter.keys())
    xs.sort()

    ys = np.cumsum(list(counter.values())).astype(float)
>>>>>>> 292a0bcb7451a62953248e3a7fb999c267b26dfd
    ys /= ys[-1]

    options = dict(linewidth=3, alpha=0.5)
    plt.step(xs, ys, where='post', **options)
    plt.xlabel('Values')
    plt.ylabel('CDF')
    plt.show()


if __name__ == '__main__':
    # main(*sys.argv)
    main("hello", "data")
