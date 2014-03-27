#!/usr/bin/env python
# -*- coding: utf-8 -*-

#    ManaulPDFgen.py --- Scribus script to generate a PDF document
#    of the lab manual
#
#    Copyright (C) 2014  Free Software Movement Karnataka http://fsmk.org
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.

import sys

try:
    import scribus
except ImportError,err:
    print "This Python script is written for the Scribus scripting interface."
    print "It can only be run from within Scribus."
    sys.exit(1)


def main(argv):
    """This is a script to generate the Lab Manual prepared by Free Software 
    Movement Karnataka (FSMK)[http://fsmk.org]."""
    
    # Close the currently open document
    if scribus.haveDoc():
        scribus.closeDoc()
    
    createNewDocument()

def createNewDocument():
    paperSize = scribus.PAPER_A4
    #paperTopMargin = paperBottomMargin = paperLeftMargin = paperRightMargin = 20
    paperMargins = (20, 20, 20, 20)
    scribus.newDoc(paperSize paperMargins, scribus.PORTRAIT, 1, scribus.UNIT_POINTS, scrisub.FACINGPAGES, scribus.FIRSTPAGERIGHT, 1)

def main_wrapper(argv):
    """The main_wrapper() function disables redrawing, sets a sensible generic
    status bar message, and optionally sets up the progress bar. It then runs
    the main() function. Once everything finishes it cleans up after the main()
    function, making sure everything is sane before the script terminates."""
    try:
        scribus.statusMessage("Preparing to generate Lab Manual...")
        scribus.progressReset()
        main(argv)
    finally:
        # Exit neatly even if the script terminated with an exception,
        # so we leave the progress bar and status bar blank and make sure
        # drawing is enabled.
        if scribus.haveDoc():
            scribus.setRedraw(True)
        scribus.statusMessage("")
        scribus.progressReset()

# This code detects if the script is being run as a script, or imported as a module.
# It only runs main() if being run as a script. This permits you to import your script
# and control it manually for debugging.
if __name__ == '__main__':
    main_wrapper(sys.argv)
