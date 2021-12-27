# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import re

# -- Project information -----------------------------------------------------

project = "Shuati"

copyright = "2021, Zeyuan Hu"
author = "Zeyuan Hu"


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    "sphinxcontrib.bibtex",
    "sphinx.ext.autosectionlabel",
    "sphinx.ext.todo",
    "sphinxcontrib.proof",
    "sphinx_markdown_tables",
    "sphinxcontrib.pseudocode"
]

# Suppress dublicate labels warning
suppress_warnings = ["autosectionlabel.*"]

# Make autosectionlabel unique
autosectionlabel_prefix_document = True

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['/problems/leetcode/*.rst']


html_last_updated_fmt = "%b %d, %Y"
# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
html_theme = "theme"

html_theme_path = ["."]

mathjax3_config = {
    "loader": {"load": ["[tex]/mathtools", "[tex]/color"]},
    "tex": {"macros": {}, "packages": {"[+]": ["mathtools", "color"]}, "tags": "ams"},
}

with open("mathsymbols.tex", "r") as f:
    for line in f:
        macros = re.findall(
            r"\\(DeclareRobustCommand|newcommand){\\(.*?)}(\[(\d)\])?{(.+)}", line
        )
        for macro in macros:
            # print(macro)
            if len(macro[2]) == 0:
                mathjax3_config["tex"]["macros"][macro[1]] = "{" + macro[4] + "}"
            else:
                mathjax3_config["tex"]["macros"][macro[1]] = [
                    "{" + macro[4] + "}",
                    int(macro[3]),
                ]
# print(mathjax3_config)

# If true, figures, tables and code-blocks are automatically numbered
# if they have a caption. The numref role is enabled.
numfig = True

# Include todo directive
todo_include_todos = True

proof_theorem_types = {
    "algorithm": "Algorithm",
    "conjecture": "Conjecture",
    "corollary": "Corollary",
    "proposition": "Proposition",
    "definition": "Definition",
    "example": "Example",
    "lemma": "Lemma",
    "observation": "Observation",
    "proof": "Proof",
    "property": "Property",
    "theorem": "Theorem",
    "assumption": "Assumption",
}

bibtex_bibfiles = ["papers.bib"]
