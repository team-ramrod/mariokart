#!/usr/bin/env python
"""makemake V0.10
Copyright (c) 2010 Michael P. Hayes, UC ECE, NZ

This program tries to make a Makefile from a template.  Given a C file
(or a directory which searched to find a C file containing a main
function) the included header files are recursively searched.  The for
each header file, a search is made for a similarly named C file.  The
header files for each C file are recursively searched and addded to
the list of found header files.  Again, similarly named C files are
searched until all the C files required for the program are found.

Usage: makemake --template template cfile search-dirs
or     makemake --template template directory search-dirs
or     makemake --builddir builddir --objext objext --template template directory search-dirs
or     makemake --builddir builddir --modules --relpath  directory search-dirs
or     makemake --builddir builddir --files --relpath  directory search-dirs

By default makemake will create a rule like foo.o: foo.c bar.h
and this will require a VPATH if the dependencies are another directory.
Alternatively, use the --relpath option to makemake to explicitly add the
relative path to the dependencies.

Note, this will die if there are circular dependencies.   FIXME!
The --modules option also needs fixing.  FIXME!

There are special strings that are replaced in the template file:
 @PROJECT@      Project name
 @VPATH@        List of source directories
 @CC@           Compiler name
 @CFLAGS@       Compiler flags
 @INCLUDES@     List of include directories each prefixed by -I
 @SRC@          List of source files
 @OBJ@          List of object files
 @CCRULES@      Rules to build object files from C files

"""

# See http://www.amk.ca/python/howto/regex/ for regular expressions in python.
# See also sre.py.
# + one or more, ? 0 or 1, * 0 or more

# http://www.cs.umd.edu/~nspring/software/style-check-readme.html

import sys
import re
import os
import subprocess
from os import pathsep
import os.path
from optparse import OptionParser


def unique (list):

    dict = {}
    for item in list:
        dict[item] = True;

    return dict.keys ()


def file_search (filename, search_path, debug):
    """Given a search path, find file
    """

    file_found = False
    paths = search_path.split (pathsep)
    for path in paths:
        if os.path.exists (os.path.join (path, filename)):
            file_found = True
            break
        
    if file_found:
        return os.path.abspath (os.path.join (path, filename))

    # FIXME, if have :: at end of search path then need to search subdirs.
        
    return None


def hfiles_get (cfile, filedeps, options):
 
    deps = filedeps[cfile]
    
    if cfile in deps:
        print >> sys.stderr, 'Circular dependency for', cfile        


    hfilelist = []

    for hfile in filedeps[cfile]:
        if hfile[-2:] == '.h':
            if options.relpath:
                hfile = os.path.relpath (hfile)
            hfilelist.append (hfile)

    for hfile in filedeps[cfile]:
        hfilelist.extend (hfiles_get (hfile, filedeps, options))

    return unique (hfilelist)


def files_get_all (filedeps, ext):

    filelist = []
    for target in filedeps:
        if target[-2:] == ext:
            filelist.append (target)

    return unique (filelist)



def cfiles_get_all (filedeps):

    return files_get_all (filedeps, '.c')


def hfiles_get_all (filedeps):

    return files_get_all (filedeps, '.h')


def paths_prune (filelist):

    relpaths = unique ([os.path.dirname (os.path.relpath (path)) for path in filelist])

    relpaths = unique (relpaths)

    if '' in relpaths:
        relpaths.remove ('')
        relpaths.insert (0, '.')

    return relpaths


def file_parse (pathname, indent, debug):

    if debug:
        print >> sys.stderr, indent, 'Parsing file', pathname

    file = open (pathname, 'r')
    text = file.read ()
    file.close ()

    # We could use the -MM option for gcc to find all the header file
    # dependencies (even with conditional compilation) but we would
    # not find the relationship between the header files.  So let's do
    # if outselves even with conditional compilation may lead us
    # astray.
    prog = re.compile (r'^#include[ ].*["<]([a-zA-Z_.0-9].*)[">]', re.MULTILINE)

    hfilelist = prog.findall (text, 0)    

    if debug:
        print >> sys.stderr, indent, 'Found hfiles', hfilelist, 'in', pathname
    return hfilelist


def makefile_print (options, template, maincfilename, filedeps, 
                    search_list):
    
    cfilelist = cfiles_get_all (filedeps)
    cfilelist.sort ()
    basecfilelist = [os.path.basename (cfile) for cfile in cfilelist]

    project = os.path.splitext (os.path.basename (maincfilename))
    project = project[0]

    file = open (template, 'r')

    text = file.read ()
    file.close ()

    hfilelist = hfiles_get_all (filedeps)

    includedirs = paths_prune (hfilelist)
    moduledirs = paths_prune (cfilelist)

    vpath = ' '.join (moduledirs)
    includes = '-I' + ' -I'.join (includedirs)
    src = ' '.join (basecfilelist)
    obj = src

    if options.builddir != '':
        objfilelist = [os.path.join (options.builddir, obj1) for obj1 in basecfilelist]
        objfilelist.sort ()
        obj = ' '.join (objfilelist)
        project = os.path.join (options.builddir, project)

    obj = re.sub (r'([a-zA-Z0-9/.-_]*)[.]c', r'\1' + options.objext, obj) 

    text = re.sub (r'@PROJECT@', project, text)
    text = re.sub (r'@VPATH@', vpath, text)
    text = re.sub (r'@CC@', options.cc, text)
    text = re.sub (r'@CFLAGS@', options.cflags, text)
    text = re.sub (r'@INCLUDES@', includes, text)
    text = re.sub (r'@SRC@', src, text)

    text = re.sub (r'@OBJ@', obj, text)

    if re.search (r'@CCRULES@', text) != None:

        search_path = pathsep.join (search_list)

        rules = ''
        for cfile in cfilelist:
            cfilebase = os.path.basename (cfile)

            if options.relpath:
                cfile1 = os.path.relpath (cfile)
            else:
                cfile1 = cfilebase

            if options.builddir != '':
                rules = rules + os.path.join (options.builddir, '')

            rules = rules + re.sub ('([a-zA-Z0-9/.-_]*)[.]c', r'\1' + options.objext, cfilebase) + ': ' + cfile1
            

            hfilelist = hfiles_get (cfile, filedeps, options)
            hfilelist.sort ()

            if options.debug:
                print >> sys.stderr, 'Need hfiles', hfilelist, 'for', cfile

            for hfile in hfilelist:
                rules = rules + ' ' + hfile

            rules = rules + '\n'
            rules = rules + '\t$(CC) -c $(CFLAGS) $< -o $@\n\n'

        text = re.sub (r'@CCRULES@', rules, text)


    print text


def maincfilename_find (dirname):

    p = subprocess.Popen (['grep -l "main[ ]*(" ' + dirname + '/*.c'],
                          shell = True, stdin = subprocess.PIPE,
                          stdout = subprocess.PIPE,
                          close_fds = True)
    
    (child_stdout, child_stdin) = (p.stdout, p.stdin)
    child_stdin.close ()
    files = child_stdout.read ()
    child_stdout.close ()

    filelist = files.strip ().split (' ')
    if not filelist:
        return None

    # What if there are multiple files with main?  For now, select the
    # first one.
    return filelist[0]


def functions_find (filepath, functiondeps, functions, options):

    command = options.compile + ' -c ' + filepath + ' -fdump-tree-cfg-raw -DDEBUG > /dev/null'
    if options.debug:
        print >> sys.stderr, command
    os.system (command)

    rtlfilename = os.path.abspath (os.path.basename (filepath)) + '.012t.cfg'

    if not os.path.exists (rtlfilename):
        return

    file = open (rtlfilename, 'r')
    text = file.readlines ()
    file.close ()

    function = None
    for line in text:
        matches = re.findall (r'^;; Function (.*)\s[(]', line)
        if matches:
            function = matches[0]
            functiondeps[function] = []
            functions[function] = filepath
            if options.debug:
                print >> sys.stderr, 'DEF', function
        matches = re.findall (r'.*gimple_call <([\w]*),', line)
        if matches:
            if options.debug:
                print >> sys.stderr, 'USE', matches[0]
            if function:
                functiondeps[function].append (matches[0])
            else:
                print >> sys.stderr, matches[0], 'used outside function in', filepath

    # Search for where a function address is taken
    function = None
    for line in text:
        matches = re.findall (r'^;; Function (.*)\s[(]', line)
        if matches:
            function = matches[0]
        #  gimple_assign <addr_expr, tasks[0].func, display_task, NULL>
        matches = re.findall (r'.*gimple_assign <addr_expr, [\w\[\].]*, ([\w]*)', line)
        if matches and functiondeps.has_key (matches[0]):
            # This is an indirect link
            functiondeps[function].append ('@' + matches[0])

    command = 'rm ' + rtlfilename
    if options.debug:
        print >> sys.stderr, command
    os.system (command)


def files_find (filepath, search_path, filedeps, moduledeps, indent, debug):

    # filedeps is a cache of all known included files

    if filedeps.has_key (filepath):
        return

    # Find included header files
    includes = file_parse (filepath, indent + '  ', debug)                
    includes2 = []

    for hfile in includes:
        hpath = file_search (hfile, search_path, debug)
        if not hpath:
            continue
        includes2.append (hpath)

    # Guess modules from header files
    modules = []
    for hpath in includes2:    
        cpath = re.sub (r'([a-zA-Z._0-9/.-_].*)[.]h', r'\1.c', hpath);
        if (not os.path.exists (cpath)) or (cpath == filepath):
            continue
        # Have found a module
        modules.append (cpath)

    base, ext = os.path.splitext (os.path.basename (filepath))
    if ext == '.c':
        
        moduledeps[base] = []
        for module in modules:
            modbase, ext = os.path.splitext (os.path.basename (module))
            moduledeps[base].append (modbase)

    filedeps[filepath] = includes2

    # Search recursively each new included file
    for file in includes2:    
        files_find (file, search_path, filedeps, moduledeps, indent + ' ', debug)

    # Search the modules
    for file in modules:    
        files_find (file, search_path, filedeps, moduledeps, indent + ' ', debug)


def alldeps_print (depsdir, options):

    for target in depsdir.keys ():

        targetbase = os.path.basename (target)
        if targetbase in options.exclude:
            continue

        deps = depsdir[target]
        deps = [dep for dep in deps if os.path.basename (dep) not in options.exclude]
        if options.relpath:
            deps = [os.path.relpath (dep) for dep in deps]

        print os.path.relpath (target) + ': ' + ' '.join (deps) + '\n'


def deps_print (target, depsdir, options, record = {}):

    if record.has_key (target):
        return
    if not depsdir.has_key (target):
        return
    
    deps = depsdir[target]

    deps = [dep for dep in deps if os.path.basename (dep) not in options.exclude]
    for dep in deps:
        # Have recursion
        if target == dep:
            continue

        deps_print (dep, depsdir, options, record)

    if options.relpath:
        deps = [os.path.relpath (dep) for dep in deps]

    record[target] = True

    print os.path.relpath (target) + ': ' + ' '.join (deps) + '\n'


def callgraph_print (target, functiondeps, functions, options, record = {}):

    if record.has_key (target):
        return
    if not functiondeps.has_key (target):
        return
    
    deps = functiondeps[target]

    deps = [dep for dep in deps if dep not in options.exclude]
    for dep in deps:
        # Have recursion
        if target == dep:
            continue
        
        if dep[0] == '@':
            dep = dep[1:]

        callgraph_print (dep, functiondeps, functions, options, record)

    record[target] = True

#    print os.path.relpath (target) + ': ' + ' '.join (deps) + '\n' + '\t' + os.path.basename (functions[target]) + '\n'

    print os.path.relpath (target) + '@' + os.path.basename (functions[target]) + ': ' + ' '.join (deps) + '\n'



class Usage (Exception):
    def __init__(self, msg):
        self.msg = msg


def main(argv = None):
    if argv is None:
        argv = sys.argv

    version = __doc__.split ('\n')[0]

    parser = OptionParser (usage = '%prog', version = version, 
                           description = __doc__)
    
    parser.add_option('--showops', action = 'store_true',
                      dest = 'showops', default = False,
                      help = 'show operations')

    parser.add_option('--modules', action = 'store_true',
                      dest = 'modules', default = False,
                      help = 'generate module dependencies')

    parser.add_option('--calls', action = 'store_true',
                      dest = 'calls', default = False,
                      help = 'generate callgraph')

    parser.add_option('--files', action = 'store_true',
                      dest = 'files', default = False,
                      help = 'generate file dependencies')

    parser.add_option('--debug', action = 'store_true',
                      dest = 'debug', default = False,
                      help = 'enable debugging')

    parser.add_option('--exclude', dest = 'exclude',
                      default = '',
                      help = 'files to exclude')

    parser.add_option('--objext', dest = 'objext',
                      default = '.o',
                      help = 'object file extension')

    parser.add_option('--exeext', dest = 'exeext',
                      default = '.out',
                      help = 'executable file extension')

    parser.add_option('--cc', dest = 'cc',
                      default = 'gcc',
                      help = 'compiler name')

    parser.add_option('--cflags', dest = 'cflags',
                      default = '',
                      help = 'CFLAGS')

    parser.add_option('--relpath', action = 'store_true',
                      dest = 'relpath', default = False,
                      help = 'use relative paths')

    parser.add_option('--outfile',  dest = 'outfilename',
                      default = None,
                      help = 'output filename')

    parser.add_option('--builddir',  dest = 'builddir',
                      default = '',
                      help = 'build dirname')

    parser.add_option('--template',  dest = 'template',
                      default = None,
                      help = 'template filename')

    (options, args) = parser.parse_args ()

    if len (args) < 1:
        print __doc__
        sys.exit (0)


    if ',' in options.exclude:
        options.exclude = options.exclude.split(',')
    else:
        options.exclude = options.exclude.split()

    maincfilename = args[0]

    search_list = []
    if len (args) > 1:
        search_list.extend (args[1:len (args)])

    search_path = pathsep.join (search_list)

    includes = '-I' + ' -I'.join (search_list)
    options.compile = options.cc + ' ' + options.cflags + ' ' + includes

    if options.debug:
        print >> sys.stderr, search_list
        print >> sys.stderr, 'template', options.template
        print >> sys.stderr, 'cfile', maincfilename
        print >> sys.stderr, 'search_path', search_path
        print >> sys.stderr, 'CWD = ', os.getcwd()
        print >> sys.stderr, options.compile

    if os.path.isdir (maincfilename):
        if options.debug:
            print >> sys.stderr, 'Searching ' + maincfilename
        maincfilename = maincfilename_find (maincfilename)
        if not maincfilename:
            sys.exit (1)

        if options.debug:
            print >> sys.stderr, 'Found C file ' + maincfilename


    # Search main c file looking for header files included with #include
    # and any header files included by the header files    

    filedeps = {}
    moduledeps = {}
    files_find (maincfilename, search_path, filedeps, moduledeps, '', options.debug)
    
    cfilelist = cfiles_get_all (filedeps)
    ofilelist = [cfile[:-2] + options.objext for cfile in cfilelist]
    outfile = maincfilename[:-2] + options.exeext
    filedeps[outfile] = ofilelist
    for ofile in ofilelist:
        deps = []
        deps.append (ofile[:-2] + '.c')
        filedeps[ofile] = deps

    if options.calls:
        functiondeps = {}
        functions = {}
        for cfile in cfilelist:
            functions_find (cfile, functiondeps, functions, options)
        callgraph_print ('main', functiondeps, functions, options)

    if options.files:
        deps_print (outfile, filedeps, options)

    if options.modules:
        target, ext = os.path.splitext (os.path.basename (maincfilename))
        deps_print (target, moduledeps, options)

    if options.template:
        makefile_print (options, options.template, maincfilename, filedeps,
                        search_list)

    return 0


if __name__ == "__main__":
    sys.exit (main())

