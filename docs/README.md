# GraphDB Research

Central documentation repo for graph database research project with Dan.

# Build the Documentation

We use [Sphinx-doc](http://www.sphinx-doc.org/en/master/) to build the documentation. Step Follows:

``` bash
$ cd graphdb-research
$ python3 -m venv env
$ source env/bin/activate
$ pip install -U Sphinx sphinxcontrib-bibtex cloud_sptheme sphinxcontrib-proof sphinx-markdown-tables
$ make html
```

# Use the Documentation

Open `build/html/index.html` in the browser after doing build.


Please pull the latest code for the change in the documentation.
