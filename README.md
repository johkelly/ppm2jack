ppm2jack
========

Command line utility to convert a .ppm file to a series of draw commands in the Jack programming language.


Planned Enhancements
====================
Optimization 1: Draw horizontal lines of pixels in groups


White Styling 1: Don't draw any white pixels. ("alpha")

White Styling 2: Don't draw edge whites (left of leftest black, right of rightest black)

White Styling 3: Only draw whites bounded by two blacks, don't share. ( |   #ww#    #w# |  <-- Draw w's, not spaces)