#! /usr/bin/python

import sys, subprocess, os
from dirwatch import Dirwatch

def f (changed_files, removed_files):
    print changed_files
    print 'Removed', removed_files
    subprocess.call(cmd)
dirs = sys.argv[1:1]
if not dirs:
    dirs = ["."]
dirs1 = sys.argv[1:]
if not dirs:
    dirs = ["."]
cmd = str.split(" ".join(dirs1))
    
Dirwatch(dirs, f, 1).watch()
