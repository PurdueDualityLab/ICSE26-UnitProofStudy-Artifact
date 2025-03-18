_rbuf_add proof
==============

This directory contains a memory safety proof for _rbuf_add.

To run the proof.
-------------
* Follow these [tool installation instructions](https://github.com/awslabs/aws-templates-for-cbmc-proofs/wiki/Installation) to install cbmc and cbmc-viewer.
* Add `cbmc`, `goto-cc`, `goto-instrument`, `goto-analyzer`, and `cbmc-viewer`
  to your path.
* Run `make`.
* Open `report/html/index.html` in a web browser.
