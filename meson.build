project('OpenSourceTerraria', 'cpp')
add_project_link_arguments(['-lcurses'], language : ['cpp'])
curses = dependency('curses', version : '>=1.0.0')
executable('ost', 'Main.cpp', 'basic_functions.cpp', dependencies: [curses], install : true, install_dir : '/usr/bin')
