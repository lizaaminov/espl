#! /usr/bin/python

import sys, subprocess, os
from dirwatch import Dirwatch

def f (changed_files, removed_files):
     print changed_files
     print 'Removed', removed_files

dirs1 = sys.argv[1]
dirs2 = sys.argv[2]
cmd = str(dirs1) + " " + str(dirs2)
print cmd
Dirwatch(dirs1, os.system(cmd), 1).watch()
