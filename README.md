# Flattr module for Gallery2

This module integrates your Gallery2 gallery with [Flattr][flattr], a
micropayment service.

[flattr]: http://flattr.com/

To install and configure this module:

* Put the files in the `modules/flattr` directory in your Gallery2
  installation (such that there is a file called
  `modules/flattr/module.inc`).

* Open "Site Admin" in your web browser, go to "Plugins", and choose
  to "install" and "activate" the Flattr plugin.

* Still in "Site Admin", go to the new item "Flattr configuration" and
  enter your Flattr username.

* Still in "Site Admin", go to "Themes", find the entry "Blocks to
  show on photo pages" and add the "Flattr micropayment button".
  (Alternatively, you can do the same for a single album.)

Now all your photos should have a Flattr button.  Your photos will not
show up on your Flattr profile immediately, only when someone actually
flattrs them.
