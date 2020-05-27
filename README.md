# ZePaSt
Ze(ro) Pa(ss) St(atistics) (C Library):
==========
"Buy one, get the rest free (terms and conditions may apply)"

----------
Computational statistics in the style of SCEADAN,
except without all those awful #ifdefs I added :/

(i.e., it *should* be bigger, better, faster #else
possibly more or less readable #endif)

----------
RN the main focus is interleaving loop bodies.
- Suppose our input vector is length N
- and we are computing M statistics,
- such as mean, median and mode (i.e., M=3)
- Normally, you would do:
  - mean   (vector)
  - median (vector)
  - mode   (vector)
- But now, you can do (something like):
  - for e in vector:
    - update mean
    - update median
    - update mode
- N.B., this doesn't decrease the asymptotic complexity,
but what it does allow for is larger loop bodies for the compiler to unroll.

Ideally, we'll add multi-threaded single-pass algorithms,
so computations can be done in sublinear time without loss of data.

And then we'll add random sampling for sub-sublinear time,
because no large software system is complete without loss of data.

----------
TODO
- variable-length n-grams
- mean/median files (i.e., compute "average" files of different types)
- conditional entropy
- statistics on the derivative (i.e., delta consecutive byte values)
- statistics on histogram
- statistics on histogram of the histogram ?
- statistics on derivative of the histogram ?
- statistics on histogram of the derivative ?

----------
[![CircleCI](https://img.shields.io/circleci/build/github/InnovAnon-Inc/ZePaSt/?color=%23FF1100&logo=InnovAnon%2C%20Inc.&logoColor=%23FF1133&style=plastic)](https://circleci.com/gh/InnovAnon-Inc/ZePaSt/)

[![Latest Release](https://img.shields.io/github/commits-since/InnovAnon-Inc/ZePaSt//latest?color=%23FF1100&include_prereleases&logo=InnovAnon%2C%20Inc.&logoColor=%23FF1133&style=plastic)](https://github.com/InnovAnon-Inc/ZePaSt//releases/latest)

[![Repo Size](https://img.shields.io/github/repo-size/InnovAnon-Inc/ZePaSt/?color=%23FF1100&logo=InnovAnon%2C%20Inc.&logoColor=%23FF1133&style=plastic)](https://github.com/InnovAnon-Inc/ZePaSt/)

![Dependencies](https://img.shields.io/librariesio/github/InnovAnon-Inc/ZePaSt/?color=%23FF1100&style=plastic)

[![License Summary](https://img.shields.io/github/license/InnovAnon-Inc/ZePaSt/?color=%23FF1100&label=Free%20Code%20for%20a%20Free%20World%21&logo=InnovAnon%2C%20Inc.&logoColor=%23FF1133&style=plastic)](https://tldrlegal.com/license/unlicense#summary)

![Corporate Logo](https://i.imgur.com/UD8y4Is.gif)

