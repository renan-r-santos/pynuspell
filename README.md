[![PyNuspell](https://img.shields.io/badge/PyNuspell-v1.0.0-green)](https://github.com/scherzocrk/pynuspell)
[![Nuspell](https://img.shields.io/badge/Nuspell-v4.2.0-green)](https://github.com/nuspell/nuspell)
[![Build](https://github.com/scherzocrk/pynuspell/actions/workflows/main.yml/badge.svg?branch=master)](https://github.com/scherzocrk/pynuspell/actions/workflows/main.yml)
[![Python](https://img.shields.io/pypi/pyversions/pynuspell.svg)](https://pypi.org/project/pynuspell/)
[![Black](https://img.shields.io/badge/code%20style-black-000000.svg)](https://github.com/psf/black)

---

# About PyNuspell

**PyNuspell** is a set of Python 3.x bindings for Nuspell spellchecking C++
library.

# About Nuspell

Nuspell is a fast and safe spelling checker software program. It is designed
for languages with rich morphology and complex word compounding.
Nuspell is written in modern C++ and it supports Hunspell dictionaries.

Main features of Nuspell spelling checker:

- Provides software library and command-line tool.
- Suggests high-quality spelling corrections.
- Backward compatibility with Hunspell dictionary file format.
- Up to 3 times faster than Hunspell.
- Full Unicode support backed by ICU.
- Twofold affix stripping (for agglutinative languages, like Azeri,
  Basque, Estonian, Finnish, Hungarian, Turkish, etc.).
- Supports complex compounds (for example, Hungarian, German and Dutch).
- Supports advanced features, for example: special casing rules
  (Turkish dotted i or German sharp s), conditional affixes, circumfixes,
  fogemorphemes, forbidden words, pseudoroots and homonyms.
- Free and open source software. Licensed under GNU LGPL v3 or later.

See more details at https://nuspell.github.io/ and
https://github.com/nuspell/nuspell

# Installing using pip

You can install this package using pip:

```
pip install pynuspell
```

To download dictionaries, please refer to
https://github.com/nuspell/nuspell/wiki/Dictionaries-and-Contacts

# Installing from source

Requirements:

- Python 3.6 or later
- Git
- C++ compiler with cmake

Open a terminal and run the following commands:

```
# Clone repository
git clone --recurse-submodules https://github.com/scherzocrk/pynuspell.git
cd pynuspell

# Install vcpkg (Windows)
.\extern\vcpkg\bootstrap-vcpkg.bat
set VCPKG_ROOT=.\extern\vcpkg

# Install vcpkg (Linux/MacOS)
.\extern\vcpkg\bootstrap-vcpkg.sh
export VCPKG_ROOT=.\extern\vcpkg

# Install nuspell
.\extern\vcpkg\vcpkg install nuspell

# Build and install pynuspell
python setup.py install

# You can generate stub files for IntelliSense using:
pip install pybind11-stubgen
pybind11-stubgen --no-setup-py pynuspell

# You can run somes tests using:
pip install pytest
pytest tests/tests.py
```

# Usage

```python
>>> import pynuspell
>>> nuspell_dict = pynuspell.load_from_path('en-US')  # path to where en_US.aff and en_US.dic are found
>>> nuspell_dict.spell('spookie')
False
>>> nuspell_dict.suggest('spookie')
['spookier', 'spook']
>>> nuspell_dict.spell('spookier')
True
```

# Next Steps

- Add more bindings to existing features
- Keep up to date with new releases of Nuspell
- Anyone is more than welcome to contribute to this package

# Contact information:

- Author: Renan Santos
- E-mail: renan.engmec@gmail.com

# Acknowledgments

Special thanks to Nuspell and PyBind11 developers

# License

PyNuspell is licensed under the LGPL version 3 or later, see LICENSE for more
information.
