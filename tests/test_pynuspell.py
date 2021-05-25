import pathlib

import pynuspell

dictionary_path = str(pathlib.Path(
    __file__).parent.absolute().joinpath('en-US'))


def test_load_from_path():
    nuspell_dict = pynuspell.load_from_path(dictionary_path)
    assert type(nuspell_dict) == pynuspell.Dictionary


def test_spell_correct():
    nuspell_dict = pynuspell.load_from_path(dictionary_path)
    assert nuspell_dict.spell('spookier') == True


def test_spell_wrong():
    nuspell_dict = pynuspell.load_from_path(dictionary_path)
    assert nuspell_dict.spell('spookie') == False


def test_suggest():
    nuspell_dict = pynuspell.load_from_path(dictionary_path)
    assert nuspell_dict.suggest('spookie') == ['spookier', 'spook']
