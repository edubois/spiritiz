EnsureSConsVersion( 1, 2 )
EnsurePythonVersion( 2, 5 )

import os
import sys

sys.path.append('tools')
from sconsProject import SConsProject

class SpiritizMatchProject( SConsProject ):
    pass

#______________________________________________________________________________#

project = SpiritizMatchProject()


Export('project')
Export({'libs':project.libs})

#______________________________________________________________________________#

project.begin()
project.SConscript()
project.end()



