Import( 'project' )
Import( 'libs' )


spiritizFlags = { 'LIBPATH': [project.inOutputLib()],
                'CCFLAGS': [project.CC['warning3'],project.CC['sharedobject'] ],
                'CXXFLAGS':[],
                'CPPDEFINES':[],
             }

if project.env['mode'] == 'production' :
	spiritizFlags['CPPDEFINES'].append( 'FACTIZ_PRODUCTION' )
	if 'visibilityhidden' in project.CC:
		spiritizFlags['SHCCFLAGS'] = [project.CC['visibilityhidden']]

# If your compiler as a flag to mark undefined flags as error in shared libraries
if 'sharedNoUndefined' in project.CC:
	spiritizFlags['SHLINKFLAGS'] = [project.CC['sharedNoUndefined']]

SConscript( [
              'libraries/spiritiz/SConscript',
            ]
            +
            project.scanFiles( ['applications'], accept=['SConscript'] )
          )

