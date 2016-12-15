retro-keyboard
--------------

Firmwares for upcycling 80's computers into USB keyboards.

Supports
--------

- Thomson MO5

Adding new keyboards
--------------------

If you want to add a firmware for an unsupported keyboard, please make
sure that you include, in addition to what's necessary to compile and
upload the firmware:
- a diagram of the keyboard matrix ([Example](mo5/keyboard-matrix.png))
- a photo showing where those rows and columns are connected ([Example](mo5/keyboard-pinout.png))
- a diagram showing where to plug the cables onto the micro-controller ([Example](microcontroller-pinout.png))
- a photo of the keyboard itself, to document its layout ([Example](keyboard.jpg))

License
-------
**GPLv2** or later. Some protocol files are under **Modified BSD License**.

Third party libraries like LUFA, PJRC and V-USB have their own license respectively.
