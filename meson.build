project('OpenSourceTerraria', 'cpp')
add_project_link_arguments(['-lcurses'], language : ['cpp'])
curses = dependency('ncurses', version : '>=6.0.0')
executable('ost', 'Main.cpp', dependencies: [curses], install : true, install_dir : '/usr/bin')
