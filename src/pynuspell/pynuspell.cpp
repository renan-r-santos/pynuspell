#include <nuspell/dictionary.hxx>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

auto suggest(nuspell::Dictionary& dict, std::string_view word)
{
    auto suggestions = std::vector<std::string>();
    dict.suggest(word, suggestions);
    return suggestions;
}

PYBIND11_MODULE(pynuspell, m)
{
    m.doc() = "Python bidings for nuspell - a fast and safe spellchecking C++ library";

    py::class_<nuspell::Dictionary>(m, "Dictionary")
        .def("spell", &nuspell::Dictionary::spell, "Checks if a given word is correct")
        .def("suggest", &suggest, "Suggests correct words for a given incorrect word");

    m.def("load_from_path", &nuspell::Dictionary::load_from_path, "Create a dictionary from files");
}
