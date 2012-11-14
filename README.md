ppm2jack
========

Command line utility to convert a .ppm file to a series of draw commands in the Jack programming language.


Planned Enhancements
====================
Optimization 1: Draw horizontal lines of pixels in groups

Optimization 2: As 1, but vertical

Optimization 2.5: Detect the better of 1 and 2, possibly mix

Optimization 3: Detect a good (or even optimal) rectangle decomposition. Good luck, and godspeed.


White Styling 1: Don't draw any white pixels. ("alpha")

White Styling 2: Don't draw edge whites (left of leftest black, right of rightest black)

White Styling 3: Only draw whites bounded by two blacks, don't share. ( |   #ww#    #w# |  <-- Draw w's, not spaces)