# megcup-2017-primary
naive solution on 2017 megcup primary question

## Author

imzhwk(klx3300@github)

## dependencies

Strangely modified *CImg* Library(can be found in qzwlecr/PassHatToDalao repository)

## compilation flags

-lpng -L/usr/X11R6/lib -lm -lpthread -lX11

## IO

only supported bmp format(dont understand why png broken)

input file:spinning_barcode.bmp
output file:output.bmp

## known bugs

segmentation fault at the end(dont know why but at least it works)
